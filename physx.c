/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static void add_phys_col(phys_cols_t *cols, float dist, vec2 to_add)
{
    if (cols->count >= MAX_COLS)
        return;
    cols->col[cols->count++] = (phys_col_t){dist, to_add};
}

static vec2 get_fun_norm(size_t i)
{
    vec2 norm[4] = {{0.0f, -1.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {-1.0f, 0.0f}};

    return (norm[i]);
}

static void test_col_fun_ext(obj_fun_t *fun, vec2 to_ext, vec2 vec,
phys_cols_t *cols)
{
    vec2 point[5] = {{fun->pos.x, fun->pos.y},
    {fun->pos.x + fun->size.x, fun->pos.y},
    {fun->pos.x + fun->size.x, fun->pos.y + fun->size.y},
    {fun->pos.x, fun->pos.y + fun->size.y}};
    seg2 seg = {{to_ext, {to_ext.x + vec.x, to_ext.y + vec.y}}};
    float ta;
    float tb;
    vec2 norm;

    if (!fun->is_collider)
        return;
    point[4] = point[0];
    for (size_t i = 0; i < 4; i++) {
        inter2d(seg, (seg2){{point[i], point[i + 1]}}, &ta, &tb);
        if (((ta >= 0.0f) && (ta <= 1.0f)) && ((tb >= 0.0f) && (tb <= 1.0f))) {
            norm = get_fun_norm(i);
            inter2d((seg2){{seg.p[1], norm}}, (seg2){{point[i], point[i + 1]}},
            &tb, NULL);
            add_phys_col(cols, dist2_sq(to_ext, seg2_interp(seg, ta)),
            vec2_sub(seg2_interp((seg2){{seg.p[1], norm}}, tb), seg.p[1]));
        }
    }
}

static void test_col_fun(cn_t *cn, obj_fun_t *fun, vec2 vec, phys_cols_t *cols)
{
    vec2 player[4] = {{cn->player.pos.x, cn->player.pos.y},
    {cn->player.pos.x + cn->player.size.x, cn->player.pos.y},
    {cn->player.pos.x, cn->player.pos.y + cn->player.size.y},
    {cn->player.pos.x + cn->player.size.x, cn->player.pos.y +
    cn->player.size.y}};

    for (size_t i = 0; i < 4; i++)
        test_col_fun_ext(fun, player[i], vec, cols);
}

static void test_col_set(cn_t *cn, objset_t set, vec2 vec, phys_cols_t *cols)
{
    for (size_t i = 0; i < set.count; i++) {
        switch (set.obj[i].type) {
        case OBJ_FUN:
            test_col_fun(cn, set.obj[i].data, vec, cols);
            break;
        default:
            break;
        }
    }
}

static void manage_is_grounded(cn_t *cn)
{
    if (cn->player.is_grounded) {
        if (cn->player.speed.x > 0.0f) {
            cn->player.speed.x -= 50.0f * cn->win.framelen;
            if (cn->player.speed.x < cn->player.maxsx) {
                cn->player.maxsx = cn->player.speed.x;
                if (cn->player.maxsx < 14.0f)
                    cn->player.maxsx = 14.0f;
            }
            if (cn->player.speed.x < 0.0f)
                cn->player.speed.x = 0.0f;
        } else if (cn->player.speed.x < 0.0f) {
            cn->player.speed.x += 50.0f * cn->win.framelen;
            if (cn->player.speed.x > -cn->player.maxsx) {
                cn->player.maxsx = cn->player.speed.x;
                if (cn->player.maxsx < 14.0f)
                    cn->player.maxsx = 14.0f;
            }
            if (cn->player.speed.x > 0.0f)
                cn->player.speed.x = 0.0f;
        }
        cn->player.is_grounded = 0;
    }
}

static void update_vector(phys_cols_t cols, vec2 *vec)
{
    uint64_t min_ndx = 0;
    uint64_t min_dist;

    if (cols.count == 0)
        return;
    min_dist = cols.col[min_ndx].dist;
    for (uint64_t i = 1; i < cols.count; i++)
        if (cols.col[i].dist < min_dist) {
            min_ndx = i;
            min_dist = cols.col[min_ndx].dist;
        }
    vec->x += cols.col[min_ndx].to_add.x;
    vec->y += cols.col[min_ndx].to_add.y;
}

void physx(cn_t *cn)
{
    vec2 vec;
    phys_cols_t cols = {0, {}};

    manage_is_grounded(cn);
    cn->player.speed.y += 30.0f * cn->win.framelen;
    vec = (vec2){cn->player.speed.x * cn->win.framelen,
    cn->player.speed.y * cn->win.framelen};
    for (size_t i = 0; i < cn->objs.count; i++) {
        if (cn->objs.set[i].z == cn->player.pos.z)
            test_col_set(cn, cn->objs.set[i], vec, &cols);
    }
    update_vector(cols, &vec);
    cn->player.speed.x = vec.x / cn->win.framelen;
    cn->player.speed.y = vec.y / cn->win.framelen;
    cn->player.pos.x += cn->player.speed.x * cn->win.framelen;
    cn->player.pos.y += cn->player.speed.y * cn->win.framelen;
}
