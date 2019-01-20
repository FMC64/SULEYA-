/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

static vec2 render_fun_get_wh(cn_t *cn, obj_fun_t *fun, float z)
{
    vec2 res;

    if (fun->sprite->scalex != 0.0f) {
        res.x = (fun->size.x / z) * (cn->win.whalf / (fun->size.x *
        fun->sprite->scalex * fun->sprite->w));
        res.y = (fun->size.y / z) * (cn->win.whalf / (fun->size.y *
        fun->sprite->scaley * fun->sprite->h));
    } else {
        res.x = (fun->size.x / z) * (cn->win.whalf / (float)fun->sprite->w);
        res.y = (fun->size.y / z) * (cn->win.whalf / (float)fun->sprite->h);
    }
    return (res);
}

void render_fun(cn_t *cn, obj_fun_t *fun)
{
    float x = fun->pos.x - cn->cam.pos.x;
    float y = fun->pos.y - cn->cam.pos.y;
    float z = fun->pos.z - cn->cam.pos.z;
    vec2 size;

    if (z <= 0.0f)
        return;
    x /= z;
    y /= z;
    x = x * cn->win.whalf + cn->win.whalf;
    y = y * cn->win.whalf + cn->win.hhalf;
    size = render_fun_get_wh(cn, fun, z);
    render_sprite(cn, fun->sprite, fun->sprite->scalex == 0.0f ? NULL :
    &(sfIntRect){0, 0, fun->size.x * fun->sprite->scalex * fun->sprite->w,
    fun->size.y * fun->sprite->scaley * fun->sprite->h},
    &(sfTransform){{size.x, 0.0f, x, 0.0f, size.y, y, 0.0f, 0.0f, 1.0f}});
}
