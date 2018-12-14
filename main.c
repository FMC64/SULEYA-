/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

void set_light(cn_t *cn, sfShader *shader)
{
    sfVector2i pos;

    pos = sfMouse_getPosition((sfWindow*)cn->win.window);
    sfShader_setFloat3Parameter(shader, "lightpos", pos.x, pos.y, 500.0f);
}

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
    editor(cn);
    quit(cn);
    return (0);
    while (poll_events(cn)) {
        sfRenderWindow_clear(cn->win.window, sfBlack);
        sfRenderWindow_display(cn->win.window);
    }
    return (EXIT_SUCCESS);
}
