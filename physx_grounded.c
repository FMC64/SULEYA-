/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static void phys_is_grounded_pos_sp(cn_t *cn)
{
    cn->player.speed.x -= 50.0f * cn->win.framelen;
    if (cn->player.speed.x < cn->player.maxsx) {
        cn->player.maxsx = cn->player.speed.x;
        if (cn->player.maxsx < 14.0f)
            cn->player.maxsx = 14.0f;
    }
    if (cn->player.speed.x < 0.0f)
        cn->player.speed.x = 0.0f;
}

static void phys_is_grounded_neg_sp(cn_t *cn)
{
    cn->player.speed.x += 50.0f * cn->win.framelen;
    if (cn->player.speed.x > -cn->player.maxsx) {
        cn->player.maxsx = cn->player.speed.x;
        if (cn->player.maxsx < 14.0f)
            cn->player.maxsx = 14.0f;
    }
    if (cn->player.speed.x > 0.0f)
        cn->player.speed.x = 0.0f;
}

void phys_is_grounded(cn_t *cn)
{
    if (cn->player.is_grounded) {
        if (cn->player.speed.x > 0.0f)
            phys_is_grounded_pos_sp(cn);
        else if (cn->player.speed.x < 0.0f)
            phys_is_grounded_neg_sp(cn);
        cn->player.is_grounded = 0;
    }
}
