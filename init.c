/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** win
*/

#include "headers.h"

void init_obj(cn_t *cn)
{
    cn->objs.count = 0;
    cn->objs.allocated = 0;
    cn->objs.set = NULL;
}

static void init_cam(cn_t *cn)
{
    cn->cam.pos = (vec3){0.0f, 0.0f, -1.0f};
    cn->cam.shift = (vec3){0.0f, 0.0f, 0.0f};
    cn->cam.ratiowh = (float)cn->win.w / (float)cn->win.h;
    cn->cam.fovw = M_PI / 2.0f;
}

void init_player(cn_t *cn)
{
    float hmin = 0.5f;
    float wmin = 0.25f;
    rect_t mesh = {wmin, hmin, 1.25f - wmin * 2.0f, 2.50f - hmin};

    cn->player.fun = add_obj_fun(cn, (vec3){0.0f, -20.0f, 0.0f},
    (vec2){1.25f, 2.50f}, cn->sprite[S_BASHO_IDLE]);
    cn->player.maxsx = 14.0;
    cn->player.is_right = 1;
    cn->player.is_moving = 0;
    cn->player.state = PLAYER_REG;
    cn->player.has_punched = 0;
    cn->player.clock = sfClock_create();
    cn->player.fun->is_collider = 0;
    cn->player.fun->is_static = 0;
    cn->player.fun->friction = 50.0f;
    cn->player.fun->mesh.vertex[0] = (vec2){mesh.x, mesh.y};
    cn->player.fun->mesh.vertex[1] = (vec2){mesh.x + mesh.w, mesh.y};
    cn->player.fun->mesh.vertex[2] = (vec2){mesh.x + mesh.w, mesh.y + mesh.h};
    cn->player.fun->mesh.vertex[3] = (vec2){mesh.x, mesh.y + mesh.h};
}

cn_t* init(void)
{
    cn_t *res;

    res = malloc_safe(sizeof(cn_t));
    if (!init_win(res))
        return (NULL);
    init_obj(res);
    init_render_buf();
    init_cam(res);
    init_input(res);
    load_sprites(res);
    init_render(res);
    srand(time(NULL));
    return (res);
}

void quit(cn_t *cn)
{
    free_objs(cn);
    unload_sprites(cn);
    sfClock_destroy(cn->win.clock);
    sfClock_destroy(cn->player.clock);
    sfClock_destroy(cn->render.clock);
    sfRenderWindow_destroy(cn->win.window);
    free(cn);
}
