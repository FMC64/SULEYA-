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
