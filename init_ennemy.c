/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** win
*/

#include "headers.h"

void init_ennemy(cn_t *cn)
{
    cn->player.clock = sfClock_create();
}

void reset_ennemy(cn_t *cn)
{
    for (size_t i = 0; i < FLAME_COUNT; i++)
        cn->flame.obj[i] = NULL;
    cn->flame.pos = (vec3){-10.0f, 0.0f, 0.0f};
    cn->flame.speed = (vec3){4.0f, 0.0f, 0.0f};
}

void spawn_flames(cn_t *cn)
{
    float start = -(float)FLAME_COUNT / 2.0f;
    obj_fun_t *fun;

    cn->flame. flame_obj = add_obj_fun(cn,
    (vec3){cn->flame.pos.x - 50.0f, start, 0.0f},
    (vec2){50.0f, (float)FLAME_COUNT}, cn->sprite[S_FLAME]);
    for (size_t i = 0; i < FLAME_COUNT; i++) {
        fun = add_obj_fun(cn, (vec3){cn->flame.pos.x,
        start + (float)i, 0.0f}, (vec2){1.0f, 1.0f},
        cn->sprite[S_FLAME_ANIM]);
        fun->is_collider = 0;
        cn->flame.obj[i] = fun;
    }
    sfSound_setLoop(cn->sound[SD_FLAME].sound, sfTrue);
    sfSound_play(cn->sound[SD_FLAME].sound);
    sfSound_setRelativeToListener(cn->sound[SD_FLAME].sound, sfTrue);
    sfSound_setAttenuation(cn->sound[SD_FLAME].sound, 1000000.0f);
}
