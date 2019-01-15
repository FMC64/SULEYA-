/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** player stuff
*/

#include "headers.h"

void update_player_sprite(cn_t *cn)
{
    if (!cn->player.is_grounded) {
        if (cn->player.is_right)
            cn->player.sprite = cn->sprite[S_BASHO_AIR];
        else
            cn->player.sprite = cn->sprite[S_BASHO_AIR_L];
        return;
    }
    if (((fabsf(cn->player.speed.x) > 0.1f) && (cn->player.is_moving))
    || ((fabsf(cn->player.speed.x) > 1.0f) && (!cn->player.is_moving))) {
        if (cn->player.is_right)
            cn->player.sprite = cn->sprite[S_BASHO_RUN];
        else
            cn->player.sprite = cn->sprite[S_BASHO_RUN_L];
    } else {
        if (cn->player.is_right)
            cn->player.sprite = cn->sprite[S_BASHO_IDLE];
        else
            cn->player.sprite = cn->sprite[S_BASHO_IDLE_L];
    }
}
