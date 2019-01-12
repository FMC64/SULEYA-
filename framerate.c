/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** win
*/

#include "headers.h"

void update_framerate(cn_t *cn)
{
    sfTime got;

    cn->win.frame++;
    if (cn->win.frame == 128) {
        got = sfClock_getElapsedTime(cn->win.clock);
        cn->win.framelen = sfTime_asSeconds(got) / 128.0f;
        printf("framelen: %f\n", cn->win.framelen);
        sfClock_restart(cn->win.clock);
        cn->win.frame = 0;
    }
}
