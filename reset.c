/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** reset stuff
*/

#include "headers.h"

static void reset_gen(cn_t *cn)
{
    add_obj_fun(cn, (vec3){0.0f, -15.0f, 0.0f}, (vec2){1.0f, 1.80f},
    cn->sprite[S_SKY]);
    add_obj_fun(cn, (vec3){0.0f, -15.0f + 1.80, 0.0f}, (vec2){5.0f, 1.0f},
    cn->sprite[S_SKY]);
    cn->gen.obj = add_obj_fun(cn, (vec3){-20.0f, 0.0f, 0.0f}, (vec2){10.0f,
    5.0f},
    cn->sprite[S_PEBBLES_MOD]);
    cn->gen.lastsky = add_obj_fun(cn, (vec3){-1100.0f, -650.0f, 1000.0f},
    (vec2){2500.0f, 1250.0f}, cn->sprite[S_SKY]);
}

void reset(cn_t *cn)
{
    free_objs(cn);
    reset_player(cn);
    reset_ennemy(cn);
    spawn_flames(cn);
    cn->misc.score = 0;
    cn->misc.is_gameover = 0;
    cn->render.render_score = 1;
    cn->playlist.is_active = 1;
    stop_music(cn);
    if (cn->gen.do_gen)
        reset_gen(cn);
    else
        load_map(cn);
}
