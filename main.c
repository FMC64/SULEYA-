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
    sfShader_setFloat3Parameter(shader, "lightpos", pos.x, pos.y, 120.0f);
}

int main(int argc, char **argv)
{
    cn_t *cn;
    sfTexture *texture;
    sfSprite *sprite;
    sfShader *shader;
    sfRenderStates states;
    int frames = 0;

    (void)argc;
    (void)argv;
    cn = init();
    if (cn == NULL)
        return (84);
    texture = sfTexture_createFromFile("res/normal.jpg", NULL);
    shader = sfShader_createFromFile("shader/light.vert", NULL, "shader/light.frag");
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    states = get_default_render_states();
    states.texture = texture;
    states.shader = shader;
    while (1) {
        set_light(cn, shader);
        sfRenderWindow_clear(cn->win.window, sfBlack);
        sfRenderWindow_drawSprite(cn->win.window, sprite, &states);
        sfRenderWindow_display(cn->win.window);
        frames++;
    }
    return (EXIT_SUCCESS);
}
