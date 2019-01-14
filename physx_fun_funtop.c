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

void phys_fun_funtop(vec2 *point, vec2 to_ext, vec2 *vec)
{
    seg2 seg = {{to_ext, {to_ext.x - vec->x, to_ext.y - vec->y}}};
    float ta;
    float tb;

    for (size_t i = 0; i < 4; i++) {
        inter2d(seg, (seg2){{point[i], point[i + 1]}}, &ta, &tb);
        if (((ta >= 0.0f) && (ta <= 1.0f)) && ((tb >= 0.0f) && (tb <= 1.0f))) {
            phys_fun_funtop_inter_found(seg, (seg2){{point[i], point[i + 1]}},
            get_p_norm(i), vec);
            seg = (seg2){{to_ext, {to_ext.x - vec->x, to_ext.y - vec->y}}};
        }
    }
}
