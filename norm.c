/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static vec2 get_norm(seg2 seg)
{
    float cos_a = cosf(-M_PI / 2.0f);
    float sin_a = sinf(-M_PI / 2.0f);
    vec2 tmp = (vec2){seg.p[1].x - seg.p[0].x, seg.p[1].y - seg.p[0].y};
    vec2 rotated;

    tmp = vec2_normalize(tmp);
    rotated.x = tmp.x * cos_a - tmp.y * sin_a;
    rotated.y = tmp.x * sin_a + tmp.y * cos_a;
    return (rotated);
}

void update_fun_norm(obj_fun_t *fun)
{
    for (size_t i = 0; i < fun->mesh.count; i++)
        fun->mesh.norm[i] =
        get_norm((seg2){{fun->mesh.vertex[i], fun->mesh.vertex[i + 1]}});
}
