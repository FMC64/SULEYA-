/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** win
*/

#include "headers.h"

cn_t* init(void)
{
    cn_t *res;

    res = malloc_safe(sizeof(cn_t));
    if (!init_win(res))
        return (NULL);
    init_render_buf();
    return (res);
}

void quit(cn_t *cn)
{
    sfRenderWindow_destroy(cn->win.window);
    free(cn);
}
