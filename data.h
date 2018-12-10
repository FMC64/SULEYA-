/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _DATA_H
#define _DATA_H

typedef struct {
uint32_t w;
uint32_t h;
float framerate;
float framelen;
sfRenderWindow *window;
} win_t;

typedef struct {
win_t win;
} cn_t;

#endif
