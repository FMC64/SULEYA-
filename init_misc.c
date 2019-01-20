/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** init
*/

#include "headers.h"

void init_misc(cn_t *cn)
{
    cn->misc.highscore = get_highscore();
    cn->gen.do_gen = get_map() == NULL;
    cn->misc.is_gameover = 0;
    cn->misc.death_barrier = 20.0f;
    srand(time(NULL));
}
