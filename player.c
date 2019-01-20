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

static void update_player_maxsp_score(cn_t *cn)
{
    if (cn->player.maxsx < cn->flame.speed.x * 1.5f)
        cn->player.maxsx = cn->flame.speed.x * 1.5f;
    if (cn->player.fun->pos.x > (float)cn->misc.score)
        cn->misc.score = cn->player.fun->pos.x;
}

static void update_player_punch(cn_t *cn)
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
}

void update_player(cn_t *cn)
{
    update_player_punch(cn);
    update_player_maxsp_score(cn);
    update_player_sprite(cn);
    if ((cn->player.fun->pos.x < cn->flame.pos.x) ||
    (cn->player.fun->pos.y > cn->misc.death_barrier))
        gameover(cn, 0);
    if ((!cn->gen.do_gen) && (cn->player.fun->pos.x > cn->misc.end))
        gameover(cn, 1);
}
