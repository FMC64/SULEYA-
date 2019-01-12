/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static vec2 get_fun_norm(size_t i)
{
    vec2 norm[4] = {{0.0f, -1.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {-1.0f, 0.0f}};

    return (norm[i]);
}

static void phys_fun_ptofun_inter_found(seg2 seg, seg2 fun_line,
vec2 norm, vec2 *vec)
{
    float t;

    if (vec2_dot(*vec, norm) >= 0.0f)
        return;
    norm = vec2_add(seg.p[1], norm);
    inter2d((seg2){{seg.p[1], norm}}, fun_line, NULL, &t);
    add_phys_col(vec2_sub(seg2_interp(fun_line, t), seg.p[1]), vec);
}

static void phys_fun_ptofun(obj_fun_t *fun, vec2 to_ext, vec2 *vec)
{
    vec2 point[5] = {{fun->pos.x, fun->pos.y},
    {fun->pos.x + fun->size.x, fun->pos.y},
    {fun->pos.x + fun->size.x, fun->pos.y + fun->size.y},
    {fun->pos.x, fun->pos.y + fun->size.y}};
    seg2 seg = {{to_ext, {to_ext.x + vec->x, to_ext.y + vec->y}}};
    float ta;
    float tb;

    if (!fun->is_collider)
        return;
    point[4] = point[0];
    for (size_t i = 0; i < 4; i++) {
        inter2d(seg, (seg2){{point[i], point[i + 1]}}, &ta, &tb);
        if (((ta >= 0.0f) && (ta <= 1.0f)) && ((tb >= 0.0f) && (tb <= 1.0f))) {
            phys_fun_ptofun_inter_found(seg, (seg2){{point[i], point[i + 1]}},
            get_fun_norm(i), vec);
            seg = (seg2){{to_ext, {to_ext.x + vec->x, to_ext.y + vec->y}}};
        }
    }
}

void phys_fun(cn_t *cn, obj_fun_t *fun, vec2 *vec)
{
    vec2 player[4] = {{cn->player.pos.x, cn->player.pos.y},
    {cn->player.pos.x + cn->player.size.x, cn->player.pos.y},
    {cn->player.pos.x, cn->player.pos.y + cn->player.size.y},
    {cn->player.pos.x + cn->player.size.x, cn->player.pos.y +
    cn->player.size.y}};

    for (size_t i = 0; i < 4; i++)
        phys_fun_ptofun(fun, player[i], vec);
}
