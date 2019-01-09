/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

void render_fun(cn_t *cn, obj_fun_t *fun)
{
    float x = fun->pos.x - cn->cam.pos.x;
    float y = fun->pos.y - cn->cam.pos.y;
    float z = fun->pos.z - cn->cam.pos.z;
    float w;
    float h;

    if (z <= 0.0f)
        return;
    x /= z;
    y /= z;
    x = x * cn->win.whalf + cn->win.whalf;
    y = y * cn->win.whalf + cn->win.hhalf;
    w = (fun->size.x / z) * (cn->win.whalf / (float)fun->sprite->w);
    h = (fun->size.y / z) * (cn->win.whalf / (float)fun->sprite->h);
    render_sprite(cn, fun->sprite, NULL,
    &(sfTransform){{w, 0.0f, x, 0.0f, h, y, 0.0f, 0.0f, 1.0f}});
}
