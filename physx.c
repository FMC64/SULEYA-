/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static void test_col_fun_ext(cn_t *cn, obj_fun_t *fun, vec2 to_ext, vec2 *vec)
{
    vec2 point[5] = {{fun->pos.x, fun->pos.y},
    {fun->pos.x + fun->size.x, fun->pos.y},
    {fun->pos.x + fun->size.x, fun->pos.y + fun->size.y},
    {fun->pos.x, fun->pos.y + fun->size.y}};
    seg2 seg = {{to_ext, {to_ext.x + vec->x, to_ext.y + vec->y}}};
    float ta;
    float tb;
    vec2 pos = {cn->player.pos.x, cn->player.pos.y};

    point[4] = point[0];
    if (!fun->is_collider)
        return;
    for (size_t i = 0; i < 4; i++) {
        inter2d(seg, (seg2){{point[i], point[i + 1]}}, &ta, &tb);
        if (((ta >= 0.0f) && (ta <= 1.0f)) && ((tb >= 0.0f) && (tb <= 1.0f))) {
            if (i % 2)
                vec->x = 0.0f;
            else {
                if (vec->y > 0.0f)
                    cn->player.is_grounded = 1;
                vec->y = 0.0f;
            }
            seg2 seg = {{to_ext, {to_ext.x + vec->x, to_ext.y + vec->y}}};
        }
    }
}

static void test_col_fun(cn_t *cn, obj_fun_t *fun, vec2 *vec)
{
    vec2 player[4] = {{cn->player.pos.x, cn->player.pos.y},
    {cn->player.pos.x + cn->player.size.x, cn->player.pos.y},
    {cn->player.pos.x, cn->player.pos.y + cn->player.size.y},
    {cn->player.pos.x + cn->player.size.x, cn->player.pos.y +
    cn->player.size.y}};

    for (size_t i = 0; i < 4; i++)
        test_col_fun_ext(cn, fun, player[i], vec);
}

static void test_col_set(cn_t *cn, objset_t set, vec2 *vec)
{
    for (size_t i = 0; i < set.count; i++) {
        switch (set.obj[i].type) {
        case OBJ_FUN:
            test_col_fun(cn, set.obj[i].data, vec);
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
            cn->player.speed.x -= 20.0f * cn->win.framelen;
            if (cn->player.speed.x < 0.0f)
                cn->player.speed.x = 0.0f;
        } else if (cn->player.speed.x < 0.0f) {
            cn->player.speed.x += 20.0f * cn->win.framelen;
            if (cn->player.speed.x > 0.0f)
                cn->player.speed.x = 0.0f;
        }
        cn->player.is_grounded = 0;
    }
}

void physx(cn_t *cn)
{
    vec2 vec;

    manage_is_grounded(cn);
    cn->player.speed.y += 30.0f * cn->win.framelen;
    //cn->player.speed.y += 9.8f * cn->win.framelen;
    vec = (vec2){cn->player.speed.x * cn->win.framelen, 0.0f};
    for (size_t i = 0; i < cn->objs.count; i++) {
        if (cn->objs.set[i].z == cn->player.pos.z)
            test_col_set(cn, cn->objs.set[i], &vec);
    }
    cn->player.speed.x = vec.x / cn->win.framelen;
    cn->player.pos.x += cn->player.speed.x * cn->win.framelen;
    vec = (vec2){0.0f, cn->player.speed.y * cn->win.framelen};
    for (size_t i = 0; i < cn->objs.count; i++) {
        if (cn->objs.set[i].z == cn->player.pos.z)
            test_col_set(cn, cn->objs.set[i], &vec);
    }
    cn->player.speed.y = vec.y / cn->win.framelen;
    cn->player.pos.y += cn->player.speed.y * cn->win.framelen;
}
