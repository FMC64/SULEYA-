/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** player stuff
*/

#include "headers.h"

static void update_player_sprite_gr_air_run_idle(cn_t *cn)
{
    if (!cn->player.fun->is_grounded) {
        if (cn->player.is_right)
            cn->player.fun->sprite = cn->sprite[S_BASHO_AIR];
        else
            cn->player.fun->sprite = cn->sprite[S_BASHO_AIR_L];
        return;
    }
    if (((fabsf(cn->player.fun->speed.x) > 0.1f) && (cn->player.is_moving))
    || ((fabsf(cn->player.fun->speed.x) > 1.0f) && (!cn->player.is_moving))) {
        if (cn->player.is_right)
            cn->player.fun->sprite = cn->sprite[S_BASHO_RUN];
        else
            cn->player.fun->sprite = cn->sprite[S_BASHO_RUN_L];
    } else {
        if (cn->player.is_right)
            cn->player.fun->sprite = cn->sprite[S_BASHO_IDLE];
        else
            cn->player.fun->sprite = cn->sprite[S_BASHO_IDLE_L];
    }
}

static void update_player_sprite(cn_t *cn)
{
    if (cn->player.state == PLAYER_PUNCHING) {
        if (cn->player.is_right)
            cn->player.fun->sprite = cn->sprite[S_BASHO_PUNCH];
        else
            cn->player.fun->sprite = cn->sprite[S_BASHO_PUNCH_L];
    } else
        update_player_sprite_gr_air_run_idle(cn);
}

static void update_player_maxsp(cn_t *cn)
{
    if (cn->player.fun->speed.x < cn->player.maxsx) {
        cn->player.maxsx = cn->player.fun->speed.x;
        if (cn->player.maxsx < 14.0f)
            cn->player.maxsx = 14.0f;
    }
    if (cn->player.fun->speed.x > -cn->player.maxsx) {
        cn->player.maxsx = cn->player.fun->speed.x;
        if (cn->player.maxsx < 14.0f)
            cn->player.maxsx = 14.0f;
    }
}

void update_player(cn_t *cn)
{
    float time;

    if (cn->player.state == PLAYER_PUNCHING) {
        time = sfTime_asSeconds(sfClock_getElapsedTime(cn->player.clock));
        if (time >= (float)cn->sprite[S_BASHO_PUNCH_L]->framecount *
        cn->sprite[S_BASHO_PUNCH_L]->framelen)
            cn->player.state = PLAYER_REG;
        if ((!cn->player.has_punched) &&
        (cn->sprite[S_BASHO_PUNCH]->frame >= 2)) {
            cn->player.has_punched = 1;
            player_punch(cn);
        }
    }
    update_player_maxsp(cn);
    update_player_sprite(cn);
}
