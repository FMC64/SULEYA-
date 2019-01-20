/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** generation !
*/

#include "headers.h"

void gen_depot_bridge_cables(cn_t *cn, vec3 pos, vec2 size)
{
    float h = 100.0f;
    obj_fun_t *fun;

    fun = add_obj_fun(cn, (vec3){pos.x, pos.y - h - 1.0f, pos.z},
    (vec2){0.04f, h}, cn->sprite[S_CABLE]);
    fun->is_collider = 0;
    fun = add_obj_fun(cn, (vec3){pos.x + size.x - 0.04f, pos.y - h - 1.0f,
    pos.z}, (vec2){0.04f, h}, cn->sprite[S_CABLE]);
    fun->is_collider = 0;
    fun = add_obj_fun(cn, (vec3){pos.x, pos.y - h - 1.0f, pos.z + 1.0f},
    (vec2){0.04f, h}, cn->sprite[S_CABLE]);
    fun = add_obj_fun(cn, (vec3){pos.x + size.x - 0.04f, pos.y - h - 1.0f,
    pos.z + 1.0f}, (vec2){0.04f, h}, cn->sprite[S_CABLE]);
}

static void gen_depot_bg_bridge(cn_t *cn)
{
    float start = 0.0f;
    float len = 8.0f + (float)(rand() % 4) * 4;
    float y = cn->gen.y + (randf() * 2.0f - 1.0f) * 20.0f;
    float z = 10.0f + randf() * 70.0f;
    obj_fun_t *fun;

    start = randf() * 3.0f;
    fun = add_obj_fun(cn, (vec3){cn->gen.x + start, y, z}, (vec2){len, 1.0f},
    cn->sprite[S_BRIDGE]);
    gen_depot_bridge_cables(cn, fun->pos, fun->size);
    add_obj_fun(cn, (vec3){cn->gen.x + start, y, z + 1.0f}, (vec2){len, 1.0f},
    cn->sprite[S_BRIDGE]);
    fun = add_obj_fun(cn, (vec3){cn->gen.x + start, y - 1.0f, z},
    (vec2){len, 1.0f}, cn->sprite[S_BARRIER]);
    fun->is_collider = 0;
    fun = add_obj_fun(cn, (vec3){cn->gen.x + start, y - 1.0f, z + 1.0f},
    (vec2){len, 1.0f}, cn->sprite[S_BARRIER]);
}

void gen_depot_bg(cn_t *cn)
{
    float bg_size = 256.0f;

    gen_depot_bg_bridge(cn);
    if (cn->gen.bg - cn->player.fun->pos.x < 200.0f) {
        add_obj_fun(cn, (vec3){cn->gen.bg, -bg_size / 2.0f, 150.0f},
        (vec2){bg_size, bg_size},
        cn->sprite[S_DEPOT_BG]);
        cn->gen.bg += bg_size;
    }
}
