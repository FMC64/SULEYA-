/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

static int poll_events(cn_t *cn)
{
    sfEvent event;

    if (!sfRenderWindow_isOpen(cn->win.window))
        return (0);
    while (sfRenderWindow_pollEvent(cn->win.window, &event))
        switch (event.type) {
            case sfEvtClosed:
            sfRenderWindow_close(cn->win.window);
            return (0);
            default:
            break;
        }
    return (1);
}

int main(int argc, char **argv, char **env)
{
    cn_t *cn;

    (void)argc;
    (void)argv;
    if (env[0] == NULL)
        return (84);
    cn = init();
    if (cn == NULL)
        return (84);
    game(cn);
    quit(cn);
    return (EXIT_SUCCESS);
}
