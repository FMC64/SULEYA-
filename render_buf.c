/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render state buffers
*/

#include "headers.h"

#define const static

const sfRenderStates states[RENDER_SLOTS];
const size_t render_count = 0;

void init_render_buf(void)
{
    sfRenderStates def = get_default_render_states();

    for (size_t i = 0; i < RENDER_SLOTS; i++)
        states[i] = def;
}

void render_sprite(cn_t *cn, sprite_t *sprite, sfIntRect *rectangle,
sfTransform *trans)
{
    (void)rectangle;
    //if (rectangle != NULL)
    //    sfSprite_setTextureRect(sprite->sprite, *rectangle);
    if (trans != NULL)
        states[render_count].transform = *trans;
    else
        states[render_count].transform = sfTransform_Identity;
    sfRenderWindow_drawSprite(cn->win.window, sprite->sprite,
    &states[render_count]);
    render_count++;
}

void render_present(cn_t *cn)
{
    sfRenderWindow_display(cn->win.window);
    render_count = 0;
}
