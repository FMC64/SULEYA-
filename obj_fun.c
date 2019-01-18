/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj insertion
*/

#include "headers.h"

void free_obj_fun(obj_fun_t *fun)
{
    if (fun->clock != NULL)
        sfClock_destroy(fun->clock);
    if (fun->is_sprite_linked) {
        sfSprite_destroy(fun->sprite->sprite);
        free(fun->sprite);
    }
    free(fun);
}

void obj_fun_set_life(obj_fun_t *fun, float life)
{
    fun->life = life;
    if (fun->clock == NULL)
        fun->clock = sfClock_create();
    sfClock_restart(fun->clock);
}
