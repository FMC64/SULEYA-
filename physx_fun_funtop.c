/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static void phys_fun_funtop_inter_found(seg2 seg, seg2 fun_line,
vec2 norm, vec2 *vectrue)
{
    float t;
    vec2 vec = {-vectrue->x, -vectrue->y};
    vec2 to_sub;

    if (vec2_dot(vec, norm) >= 0.0f)
        return;
    norm = vec2_add(seg.p[1], norm);
    inter2d((seg2){{seg.p[1], norm}}, fun_line, NULL, &t);
    to_sub = vec2_sub(seg2_interp(fun_line, t), seg.p[1]);
    vectrue->x -= to_sub.x * 1.1;
    vectrue->y -= to_sub.y * 1.1;
}

void phys_fun_funtop(mesh_t *fun, vec2 to_ext, vec2 *vec)
{
    seg2 seg = {{to_ext, {to_ext.x - vec->x, to_ext.y - vec->y}}};
    seg2 seg_fun;
    float ta;
    float tb;

    for (size_t i = 0; i < fun->count; i++) {
        seg_fun = (seg2){{fun->vertex[i], fun->vertex[i + 1]}};
        inter2d(seg, seg_fun, &ta, &tb);
        if (((ta >= 0.0f) && (ta <= 1.0f)) && ((tb >= 0.0f) && (tb <= 1.0f))) {
            phys_fun_funtop_inter_found(seg, seg_fun, fun->norm[i], vec);
            seg = (seg2){{to_ext, {to_ext.x - vec->x, to_ext.y - vec->y}}};
        }
    }
}
