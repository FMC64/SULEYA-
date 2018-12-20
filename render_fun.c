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
    x = x * (float)(cn->win.w / 2) + (float)(cn->win.w / 2);
    y = -y * (float)(cn->win.w / 2) + (float)(cn->win.h / 2);
    w = (fun->size.x / z) * ((float)(cn->win.w / 2) / (float)fun->sprite->w);
    h = (fun->size.y / z) * ((float)(cn->win.w / 2) / (float)fun->sprite->h);
    y -= h * (float)fun->sprite->h;
    render_sprite(cn, fun->sprite, NULL,
    &(sfTransform){{w, 0.0f, x, 0.0f, h, y, 0.0f, 0.0f, 1.0f}});
}
