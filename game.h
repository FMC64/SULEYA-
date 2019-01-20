/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** game
*/

#ifndef _GAME_H
#define _GAME_H

int intro(cn_t *cn);

int menu(cn_t *cn);
int menu_input(cn_t *cn);

int poll_events(cn_t *cn);
void game(cn_t *cn);

void reset(cn_t *cn);

void gameover(cn_t *cn, int has_won);
void gameover_update(cn_t *cn);

#endif
