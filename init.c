/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** win
*/

#include "headers.h"

static void init_obj(cn_t *cn)
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
    return (res);
}

void quit(cn_t *cn)
{
    free_objs(cn);
    sfRenderWindow_destroy(cn->win.window);
    free(cn);
}
