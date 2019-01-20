/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

uint64_t get_pow(void)
{
    uint64_t res = 1;

    for (size_t i = 1; i < SCORE_DIGITS; i++)
        res *= 10;
    return (res);
}

void render_score(cn_t *cn)
{
    uint32_t x = cn->render.score_x;
    uint32_t y = cn->render.score_y;
    uint64_t digit;
    uint64_t pow = get_pow();

    for (size_t i = 0; i < SCORE_DIGITS; i++) {
        digit = (cn->misc.score / pow) % 10;
        render_sprite(cn, cn->sprite[S_FONT_SFAMICOM], &(sfIntRect){digit * 64,
        0, 64, 64}, &(sfTransform){{1.0f, 0.0f, x + i * 64, 0.0f, 1.0f, y, 0.0f,
        0.0f, 1.0f}});
        pow /= 10;
    }
}

void render_highscore(cn_t *cn)
{
    uint32_t x = cn->render.score_x;
    uint32_t y = cn->render.score_y + 128;
    uint64_t digit;
    uint64_t pow = get_pow();

    for (size_t i = 0; i < SCORE_DIGITS; i++) {
        digit = (cn->misc.highscore / pow) % 10;
        render_sprite(cn, cn->sprite[S_FONT_SFAMICOM], &(sfIntRect){digit * 64,
        0, 64, 64}, &(sfTransform){{1.0f, 0.0f, x + i * 64, 0.0f, 1.0f, y, 0.0f,
        0.0f, 1.0f}});
        pow /= 10;
    }
}
