/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** generation !
*/

#include "headers.h"

obj_fun_t* gen_ter(cn_t *cn, vec3 lastpos, vec2 lastsize, sprite_t *sprite)
{
    float h = randf() * 2.0f;
    obj_fun_t *fun;

    if ((rand() % 100) > 2) {
        fun = add_obj_fun(cn, (vec3){lastpos.x + lastsize.x,
        -h - 1.0f - randf() * 8.0f, lastpos.z}, (vec2){randf() * 10.0f,
        randf() * 3.0f}, sprite);
        if ((rand() % 20) < 10) {
            fun->mesh.vertex[0] = fun->mesh.vertex[1];
            fun->mesh.vertex[1] = fun->mesh.vertex[2];
            fun->mesh.vertex[2] = fun->mesh.vertex[3];
            fun->mesh.vertex[3] = fun->mesh.vertex[0];
            fun->mesh.count = 3;
            update_fun_norm(fun);
            fun->sprite = cn->sprite[S_PEBBLES_MOD_HALF];
        }
        fun->is_destroyable = 1;
    }
    return (add_obj_fun(cn, (vec3){lastpos.x + lastsize.x, -h, lastpos.z},
    (vec2){((float)rand() / (float)RAND_MAX) * 5.0f, h}, sprite));
}

void gen_pub(cn_t *cn, sprite_t *bendy, sprite_t *tree, vec3 pos)
{
    size_t count = rand() % 50;
    float h;

    for (size_t i = 0; i < count; i++) {
        add_obj_fun(cn, (vec3){pos.x + ((float)rand() / (float)RAND_MAX) *
        10.0f,
        pos.y - ((float)rand() / (float)RAND_MAX) * 1.0f - 2.0f,
        pos.z + 8.0f + ((float)rand() / (float)RAND_MAX) * 50.0f},
        (vec2){1.0f, 1.5f + ((float)rand() / (float)RAND_MAX) * 0.5f}, bendy);
    }
    count = rand() % 50;
    for (size_t i = 0; i < count; i++) {
        h = 7.0f + ((float)rand() / (float)RAND_MAX) * 3.0f;
        add_obj_fun(cn, (vec3){pos.x + ((float)rand() / (float)RAND_MAX) *
        10.0f,
        pos.y - ((float)rand() / (float)RAND_MAX) * 1.0f - h,
        pos.z + 20.0f + ((float)rand() / (float)RAND_MAX) * 100.0f},
        (vec2){5.0f, h}, tree);
    }
}

obj_fun_t* gen_sky(cn_t *cn, obj_fun_t *last, sprite_t *sky)
{
    return (add_obj_fun(cn, (vec3){last->pos.x + last->size.x, last->pos.y,
    last->pos.z}, last->size, sky));
}
