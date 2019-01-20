/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** generation !
*/

#include "headers.h"

void gen_depot_box(cn_t *cn, vec3 pos, vec2 size)
{
    obj_fun_t *fun;
    int count;
    float dim;
    float acc = 0.0f;
    float start = randf() * size.x;

    if ((rand() % 2) == 1) {
        count = rand() % 5;
        for (int i = 0; i < count; i++) {
            dim = 1.0f + randf() * 2.0f;
            acc += dim * 1.01;
            fun = add_obj_fun(cn, (vec3){pos.x + start + randf() - 0.5f,
            pos.y - acc, pos.z}, (vec2){dim, dim}, cn->sprite[S_BOX]);
            fun->is_destroyable = 1;
            fun->is_static = 0;
        }
    }
}
