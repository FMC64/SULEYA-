/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

static void poll_input_lr(cn_t *cn)
{
    float acc = 50.0f;

    if (cn->input.keystate[KEY_LEFT]) {
        cn->player.fun->speed.x -=
        (AIRSTRAFE + acc * (float)cn->player.fun->is_grounded) *
        cn->win.framelen;
        if (cn->player.fun->speed.x < -cn->player.maxsx)
            cn->player.fun->speed.x = -cn->player.maxsx;
    }
    if (cn->input.keystate[KEY_RIGHT]) {
        cn->player.fun->speed.x +=
        (AIRSTRAFE + acc * (float)cn->player.fun->is_grounded) *
        cn->win.framelen;
        if (cn->player.fun->speed.x > cn->player.maxsx)
            cn->player.fun->speed.x = cn->player.maxsx;
    }
}

static void poll_atk(cn_t *cn)
{
    if (cn->input.keystate[KEY_ATK] && (!cn->input.prev[KEY_ATK])) {
        if (cn->player.state == PLAYER_PUNCHING)
            return;
        sfClock_restart(cn->player.clock);
        cn->player.state = PLAYER_PUNCHING;
        cn->player.has_punched = 0;
        sfClock_restart(cn->sprite[S_BASHO_PUNCH]->clock);
        sfClock_restart(cn->sprite[S_BASHO_PUNCH_L]->clock);
    }
}

static void input_jump(cn_t *cn)
{
    float acc = (11.0f + (fabsf(cn->player.fun->speed.x) /
    cn->player.maxsx) * 9.0f);
    float time = (float)cn->player.fun->last_grounded * cn->win.framelen;
    float acc_fin = -30.0f * cn->win.framelen - acc *
    8.0 * cn->win.framelen;

    if (cn->input.keystate[KEY_JUMP] && cn->player.fun->is_grounded)
        cn->player.can_jump = 1;
    if (cn->input.keystate[KEY_JUMP] && cn->player.can_jump &&
    (time + cn->win.framelen < 0.1f))
            cn->player.fun->speed.y += acc_fin;
    if ((time > 0.2f) || (!cn->input.keystate[KEY_JUMP]))
        cn->player.can_jump = 0;
}

void process_input(cn_t *cn)
{
    input_jump(cn);
    poll_input_lr(cn);
    if (cn->input.keystate[KEY_LEFT] || cn->input.keystate[KEY_RIGHT]) {
        cn->player.is_right = cn->input.keystate[KEY_RIGHT];
        cn->player.is_moving = 1;
    } else
        cn->player.is_moving = 0;
    poll_atk(cn);
}
