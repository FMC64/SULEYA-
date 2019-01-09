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

void poll_input(cn_t *cn)
{
    float acc = 0.5f;
    //float acc = 0.01f;

    for (size_t i = 0; i < KEY_COUNT; i++)
        cn->input.keystate[i] = sfKeyboard_isKeyPressed(cn->input.binding[i]);
    if (cn->input.keystate[KEY_UP]) {
        cn->cam.pos.y -= CAM_MOVE;
        cn->player.speed.y = -20.0f;
        //cn->player.speed.y = -2.0f;
    }
    if (cn->input.keystate[KEY_DOWN])
        cn->cam.pos.y += CAM_MOVE;
    if (cn->input.keystate[KEY_LEFT]) {
        cn->cam.pos.x -= CAM_MOVE;
        cn->player.speed.x -= acc;
        if (cn->player.speed.x < -10.0f)
            cn->player.speed.x = -10.0f;
    }
    if (cn->input.keystate[KEY_RIGHT]) {
        cn->cam.pos.x += CAM_MOVE;
        cn->player.speed.x += acc;
        if (cn->player.speed.x > 10.0f)
            cn->player.speed.x = 10.0f;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        cn->cam.pos.z += CAM_MOVE;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        cn->cam.pos.z -= CAM_MOVE;
}
