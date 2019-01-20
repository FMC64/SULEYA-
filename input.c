/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

void init_input(cn_t *cn)
{
    cn->input.binding[KEY_UP] = sfKeyUp;
    cn->input.binding[KEY_DOWN] = sfKeyDown;
    cn->input.binding[KEY_LEFT] = sfKeyLeft;
    cn->input.binding[KEY_RIGHT] = sfKeyRight;
    cn->input.binding[KEY_JUMP] = sfKeyX;
    cn->input.binding[KEY_ATK] = sfKeyW;
    for (size_t i = 0; i < KEY_COUNT; i++)
        cn->input.prev[i] = 0;
    for (size_t i = 0; i < KEY_COUNT; i++)
        cn->input.keystate[i] = 0;
}

void get_raw_input(cn_t *cn)
{
    for (size_t i = 0; i < KEY_COUNT; i++)
        cn->input.prev[i] = cn->input.keystate[i];
    for (size_t i = 0; i < KEY_COUNT; i++)
        cn->input.keystate[i] = sfKeyboard_isKeyPressed(cn->input.binding[i]);
}

static void poll_input_lr(cn_t *cn)
{
    float acc = 50.0f;

    if (cn->input.keystate[KEY_LEFT]) {
        cn->player.fun->speed.x -=
        (AIRSTRAFE + acc * (float)cn->player.fun->is_grounded) *
        cn->win.framelen;
        if (cn->player.fun->speed.x < -cn->player.maxsx) {
            cn->player.fun->speed.x = -cn->player.maxsx;
            cn->player.maxsx += 1.4 * cn->win.framelen;
        }
    }
    if (cn->input.keystate[KEY_RIGHT]) {
        cn->player.fun->speed.x +=
        (AIRSTRAFE + acc * (float)cn->player.fun->is_grounded) *
        cn->win.framelen;
        if (cn->player.fun->speed.x > cn->player.maxsx) {
            cn->player.fun->speed.x = cn->player.maxsx;
            cn->player.maxsx += 1.4 * cn->win.framelen;
        }
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

void process_input(cn_t *cn)
{
    if (cn->input.keystate[KEY_JUMP] && (!cn->input.prev[KEY_JUMP]) &&
    cn->player.fun->is_grounded)
        cn->player.fun->speed.y =
        -(11.0f + (fabsf(cn->player.fun->speed.x) / cn->player.maxsx) * 9.0f);
    poll_input_lr(cn);
    if (cn->input.keystate[KEY_LEFT] || cn->input.keystate[KEY_RIGHT]) {
        cn->player.is_right = cn->input.keystate[KEY_RIGHT];
        cn->player.is_moving = 1;
    } else
        cn->player.is_moving = 0;
    poll_atk(cn);
}
