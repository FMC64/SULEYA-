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
}

static void poll_input_lr(cn_t *cn)
{
    float airstrafe = 50.0f;
    float acc = 50.0f;

    if (cn->input.keystate[KEY_LEFT]) {
        cn->player.fun->speed.x -=
        (airstrafe + acc * (float)cn->player.fun->is_grounded) *
        cn->win.framelen;
        if (cn->player.fun->speed.x < -cn->player.maxsx) {
            cn->player.fun->speed.x = -cn->player.maxsx;
            cn->player.maxsx += 1.4 * cn->win.framelen;
        }
    }
    if (cn->input.keystate[KEY_RIGHT]) {
        cn->player.fun->speed.x +=
        (airstrafe + acc * (float)cn->player.fun->is_grounded) *
        cn->win.framelen;
        if (cn->player.fun->speed.x > cn->player.maxsx) {
            cn->player.fun->speed.x = cn->player.maxsx;
            cn->player.maxsx += 1.4 * cn->win.framelen;
        }
    }
}

static void poll_atk(cn_t *cn)
{
    if (cn->input.keystate[KEY_ATK]) {
        if (cn->player.state == PLAYER_PUNCHING)
            return;
        sfClock_restart(cn->player.clock);
        cn->player.state = PLAYER_PUNCHING;
        cn->player.has_punched = 0;
        sfClock_restart(cn->sprite[S_BASHO_PUNCH]->clock);
        sfClock_restart(cn->sprite[S_BASHO_PUNCH_L]->clock);
    }
}

void poll_input(cn_t *cn)
{
    obj_fun_t *fun;
    float w;

    for (size_t i = 0; i < KEY_COUNT; i++)
        cn->input.keystate[i] = sfKeyboard_isKeyPressed(cn->input.binding[i]);
    if (cn->input.keystate[KEY_UP] && cn->player.fun->is_grounded)
        cn->player.fun->speed.y =
        -(11.0f + (fabsf(cn->player.fun->speed.x) / cn->player.maxsx) * 9.0f);
    poll_input_lr(cn);
    if (cn->input.keystate[KEY_LEFT] || cn->input.keystate[KEY_RIGHT]) {
        cn->player.is_right = cn->input.keystate[KEY_RIGHT];
        cn->player.is_moving = 1;
    } else
        cn->player.is_moving = 0;
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        w = ((float)rand() / (float)RAND_MAX) * 0.8f + 0.1f;
        fun = add_obj_fun(cn, (vec3){cn->player.fun->pos.x,
        cn->player.fun->pos.y - 4.0f, 0.0f}, (vec2){w, w},
        cn->sprite[S_SKY]);
        fun->is_static = 0;
        fun->is_collider = 0;
        //fun->friction = 10.0f;
        //fun->bounce = 3.0f;
        fun->speed.x = ((float)rand() / (float)RAND_MAX) * 10.0f - 5.0f;
        fun->speed.y = ((float)rand() / (float)RAND_MAX) * 10.0f - 5.0f;
        obj_fun_set_life(fun, 15.0f);
    }
    poll_atk(cn);
}
