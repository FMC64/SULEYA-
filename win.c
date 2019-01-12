/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** win
*/

#include "headers.h"

static float get_nearest_framerate(float framelen)
{
    float rate[WIN_REFRESH_NB] =
    {50.0f, 60.0f, 75.0f, 90.0f, 120.0f, 144.0f, 240.0f};
    float delta;
    float min_delta = rate[0];
    size_t min_delta_ndx = 0;
    float currate = 1.0 / framelen;

    //return (5.0f);
    printf("currate: %f\n", currate);
    for (size_t i = 0; i < WIN_REFRESH_NB; i++) {
        delta = rate[i] - currate;
        if (delta < 0.0f)
            delta = -delta;
        if (delta < min_delta) {
            min_delta = delta;
            min_delta_ndx = i;
        }
    }
    return (rate[min_delta_ndx]);
}

static float conv_sftime(void *src)
{
    int64_t got;

    got = *(int64_t*)src;
    return ((float)got);
}

static float get_framerate(cn_t *cn)
{
    sfClock *clock;
    float res;
    sfTime got;

    clock = sfClock_create();
    if (clock == NULL)
        exit_full_custom();
    sfClock_restart(clock);
    for (size_t i = 0; i < 32; i++) {
        sfRenderWindow_clear(cn->win.window, sfBlack);
        sfRenderWindow_display(cn->win.window);
    }
    got = sfClock_getElapsedTime(clock);
    res = (conv_sftime(&got) / 1000000.0f) / 32.0f;
    sfClock_destroy(clock);
    return (get_nearest_framerate(res));
}

int init_win(cn_t *cn)
{
    cn->win.w = 1920;
    cn->win.h = 1080;
    cn->win.whalf = (float)cn->win.w / 2.0f;
    cn->win.hhalf = (float)cn->win.h / 2.0f;
    cn->win.window = sfRenderWindow_create((sfVideoMode){cn->win.w,
    cn->win.h, 32},
    "SULEYA-", sfFullscreen | sfClose, NULL);
    if (cn->win.window == NULL)
        return (0);
    sfWindow_setVerticalSyncEnabled((sfWindow*)cn->win.window, sfTrue);
    cn->win.framerate = get_framerate(cn);
    cn->win.framelen = 1.0f / cn->win.framerate;
    sfRenderWindow_setFramerateLimit(cn->win.window,
    (uint32_t)cn->win.framerate);
    printf("framerate: %f\nframelen: %f\n", cn->win.framerate, cn->win.framelen);
    cn->win.frame = 0;
    cn->win.clock = sfClock_create();
    sfClock_restart(cn->win.clock);
    return (1);
}
