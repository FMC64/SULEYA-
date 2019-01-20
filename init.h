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

void init_cam(cn_t *cn);
cn_t* init(void);
int init_win(cn_t *cn);
void init_player(cn_t *cn);
void reset_player(cn_t *cn);
void init_obj(cn_t *cn);

void quit(cn_t *cn);

void init_render(cn_t *cn);

void init_ennemy(cn_t *cn);
void reset_ennemy(cn_t *cn);
void spawn_flames(cn_t *cn);

void init_playlist(cn_t *cn);

uint64_t get_highscore(void);
void set_highscore(uint64_t score);

void init_misc(cn_t *cn);

#endif
