/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** menu
*/

#include "headers.h"

int menu_input(cn_t *cn)
{
    if (sfKeyboard_isKeyPressed(cn->input.binding[KEY_ATK]))
        return (0);
    else
        return (1);
}
