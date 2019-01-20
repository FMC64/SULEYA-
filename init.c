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

void init_cam(cn_t *cn)
{
    cn->cam.pos = (vec3){0.0f, 0.0f, -1.0f};
    cn->cam.shift = (vec3){0.0f, 0.0f, 0.0f};
    cn->cam.ratiowh = (float)cn->win.w / (float)cn->win.h;
    cn->cam.fovw = M_PI / 2.0f;
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
    load_sounds(res);
    init_render(res);
    init_ennemy(res);
    init_player(res);
    init_playlist(res);
    init_misc(res);
    return (res);
}

void quit(cn_t *cn)
{
    free_objs(cn);
    stop_music(cn);
    unload_sounds(cn);
    unload_sprites(cn);
    sfClock_destroy(cn->win.clock);
    sfClock_destroy(cn->player.clock);
    sfClock_destroy(cn->render.clock);
    sfRenderWindow_destroy(cn->win.window);
    free(cn);
}
