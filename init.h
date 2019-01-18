/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** win
*/

#ifndef _INIT_H
#define _INIT_H

#include "headers.h"

#define WIN_REFRESH_NB 7

cn_t* init(void);
int init_win(cn_t *cn);
void init_player(cn_t *cn);
void init_obj(cn_t *cn);

void quit(cn_t *cn);

#endif
