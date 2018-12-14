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

void editor(cn_t *cn)
{
    sprite_t *sprite;
    uint64_t frame = 0;
    float cos;
    float sin;
    sfTransform trans;

    sprite = create_sprite("res/pebbles.jpg");
    while (poll_events(cn)) {
        sfRenderWindow_clear(cn->win.window, sfBlack);
        cos = cosf((float)frame / 100.0f);
        sin = sinf((float)frame / 100.0f);
        render_sprite(cn, sprite, &(sfIntRect){500, 700, 100, 100}, NULL);
        for (size_t i = 0; i < 50; i++) {
        trans = (sfTransform){{1, 0, 250, 0, 1, 125, 0, 0, 1}};
        trans_mul(&(sfTransform){{cos, -sin, 0, sin, cos,
        0, 0, 0, 1}}, &trans);
        trans_mul(&(sfTransform){{1, 0, 100, 0, 1,
        50, 0, 0, 1}}, &trans);
        trans_mul(&(sfTransform){{(float)i / 30.0f, 0, 0, 0, (float)i / 30.0f,
        0, 0, 0, 1}}, &trans);
        trans_mul(&(sfTransform){{1, 0, 100 + i * 16, 0, 1,
        100 + i * 8, 0, 0, 1}}, &trans);
        render_sprite(cn, sprite, &(sfIntRect){i * 8, 700, 200, 100},
        &trans);
        }
        sfRenderWindow_display(cn->win.window);
        frame++;
    }
    destroy_sprite(sprite);
}
