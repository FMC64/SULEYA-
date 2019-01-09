/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

void render_player(cn_t *cn)
{
    float x = cn->player.pos.x - cn->cam.pos.x;
    float y = cn->player.pos.y - cn->cam.pos.y;
    float z = cn->player.pos.z - cn->cam.pos.z;
    float w;
    float h;

    if (z <= 0.0f)
        return;
    x /= z;
    y /= z;
    x = x * cn->win.whalf + cn->win.whalf;
    y = y * cn->win.whalf + cn->win.hhalf;
    w = (cn->player.size.x / z) * (cn->win.whalf / (float)cn->player.sprite->w);
    h = (cn->player.size.y / z) * (cn->win.whalf / (float)cn->player.sprite->h);
    render_sprite(cn, cn->player.sprite, NULL,
    &(sfTransform){{w, 0.0f, x, 0.0f, h, y, 0.0f, 0.0f, 1.0f}});
}
