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
    sprite_t *sprite;

    (void)argc;
    (void)argv;
    if (env[0] == NULL)
        return (84);
    cn = init();
    if (cn == NULL)
        return (84);
    sprite = create_sprite("res/pebbles.jpg");
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            for (int k = 0; k < 20; k++)
                add_obj_fun(cn, (vec3){i * 4, j * 4, k * 4}, (vec2){1.0f, 1.0f}, sprite);
    while (poll_events(cn)) {
        poll_input(cn);
        sfRenderWindow_clear(cn->win.window, sfBlack);
        render(cn);
        render_present(cn);
    }
    destroy_sprite(sprite);
    quit(cn);
    return (EXIT_SUCCESS);
}
