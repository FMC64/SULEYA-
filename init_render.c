/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** fx
*/

#include "headers.h"

void init_render(cn_t *cn)
{
    cn->render.is_dithering = 0;
    cn->render.clock = sfClock_create();
}

void set_dithering(cn_t *cn, int is_fading, float time)
{
    cn->render.is_dithering = 1;
    cn->render.dither_is_fading = is_fading;
    cn->render.dithering_laps = time;
    cn->render.is_dither_done = 0;
    sfClock_restart(cn->render.clock);
}
