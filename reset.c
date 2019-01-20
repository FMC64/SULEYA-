/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** reset stuff
*/

#include "headers.h"

static void reset_gen(cn_t *cn)
{
    cn->gen.x = -20.0f;
    cn->gen.y = 0.0f;
    cn->gen.bg = -150.0f;
    cn->gen.depot.is_bridge = 0;
    cn->gen.depot.light = -20.0f;
    cn->gen.biome = BIOME_DEPOT;
    add_obj_fun(cn, (vec3){-2.0f, 0.0f, 0.0f}, (vec2){4.0f, 1.0f},
    cn->sprite[S_FLOOR1]);
}

void reset(cn_t *cn)
{
    free_objs(cn);
    reset_player(cn);
    cn->player.fun->speed.y = 60.0f;
    cn->player.fun->pos.y = -35.0f;
    reset_ennemy(cn);
    spawn_flames(cn);
    cn->misc.score = 0;
    cn->misc.is_gameover = 0;
    cn->render.render_score = 1;
    cn->playlist.is_active = 1;
    stop_music(cn);
    init_cam(cn);
    if (cn->gen.do_gen)
        reset_gen(cn);
    else
        load_map(cn);
}
