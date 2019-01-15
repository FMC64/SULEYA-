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
        cn->player.speed.x -=
        (airstrafe + acc * (float)cn->player.is_grounded) * cn->win.framelen;
        if (cn->player.speed.x < -cn->player.maxsx) {
            cn->player.speed.x = -cn->player.maxsx;
            cn->player.maxsx += 4.0 * cn->win.framelen;
        }
    }
    if (cn->input.keystate[KEY_RIGHT]) {
        cn->player.speed.x +=
        (airstrafe + acc * (float)cn->player.is_grounded) * cn->win.framelen;
        if (cn->player.speed.x > cn->player.maxsx) {
            cn->player.speed.x = cn->player.maxsx;
            cn->player.maxsx += 4.0 * cn->win.framelen;
        }
    }
}

void poll_input(cn_t *cn)
{
    for (size_t i = 0; i < KEY_COUNT; i++)
        cn->input.keystate[i] = sfKeyboard_isKeyPressed(cn->input.binding[i]);
    if (cn->input.keystate[KEY_UP] && cn->player.is_grounded)
        cn->player.speed.y =
        -(13.0f + (fabsf(cn->player.speed.x) / cn->player.maxsx) * 7.0f);
    poll_input_lr(cn);
    if (cn->input.keystate[KEY_LEFT] || cn->input.keystate[KEY_RIGHT]) {
        cn->player.is_right = cn->input.keystate[KEY_RIGHT];
        cn->player.is_moving = 1;
    } else
        cn->player.is_moving = 0;
}
