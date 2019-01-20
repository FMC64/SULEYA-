/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** input headers
*/

#ifndef _INPUT_STRUCT_H
#define _INPUT_STRUCT_H

typedef enum {
    KEY_UP = 0,
    KEY_DOWN = 1,
    KEY_LEFT = 2,
    KEY_RIGHT = 3,
    KEY_JUMP = 4,
    KEY_ATK = 5,
    KEY_COUNT = 6
} key_act_t;

typedef struct {
    sfKeyCode binding[KEY_COUNT];
    char keystate[KEY_COUNT];
    char prev[KEY_COUNT];
} input_t;

#endif

