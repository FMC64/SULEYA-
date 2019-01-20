/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** generation !
*/

#include "headers.h"

static void gen_depot_bridge(cn_t *cn)
{
    float start = 0.0f;
    float len = 4.0f + (float)(rand() % 3) * 4;
    float y = cn->gen.y + (randf() * 2.0f - 1.0f) * 2.5f;
    obj_fun_t *fun;

    start = 1.0f + randf() * 3.0f;
    fun = add_obj_fun(cn, (vec3){cn->gen.x + start, y, 0.0f}, (vec2){len, 1.0f},
    cn->sprite[S_BRIDGE]);
    gen_depot_bridge_cables(cn, fun->pos, fun->size);
    add_obj_fun(cn, (vec3){cn->gen.x + start, y, 1.0f}, (vec2){len, 1.0f},
    cn->sprite[S_BRIDGE]);
    fun = add_obj_fun(cn, (vec3){cn->gen.x + start, y - 1.0f, 0.0f},
    (vec2){len, 1.0f}, cn->sprite[S_BARRIER]);
    fun->is_collider = 0;
    fun = add_obj_fun(cn, (vec3){cn->gen.x + start, y - 1.0f, 1.0f},
    (vec2){len, 1.0f}, cn->sprite[S_BARRIER]);
    cn->gen.x += start + len;
    cn->gen.y = y;
}

static void gen_depot_reg(cn_t *cn)
{
    float start = 0.0f;
    float len = 3.0f + randf() * 5.0f;
    float y = cn->gen.y + (randf() * 2.0f - 1.0f) * 2.5f;

    if ((rand() % 100) < 15)
        start = 2.0f + randf() * 2.0f;
    add_obj_fun(cn, (vec3){cn->gen.x + start, y, 0.0f}, (vec2){len, 1.0f},
    cn->sprite[S_FLOOR1]);
    add_obj_fun(cn, (vec3){cn->gen.x + start, y + 1.0f, 0.0f},
    (vec2){len, 50.0f}, cn->sprite[S_FLOOR2]);
    add_obj_fun(cn, (vec3){cn->gen.x + start, y + 1.0f, -0.01f},
    (vec2){len, 1.0f}, cn->sprite[S_DITHER_DOWN]);
    cn->gen.x += start + len;
    cn->gen.y = y;
}

void gen_depot(cn_t *cn)
{
    gen_depot_bg(cn);
    if ((rand() % 100) > 95)
        cn->gen.depot.is_bridge = !cn->gen.depot.is_bridge;
    if (cn->gen.depot.is_bridge)
        gen_depot_bridge(cn);
    else
        gen_depot_reg(cn);
}
