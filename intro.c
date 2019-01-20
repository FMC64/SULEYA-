/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** intro
*/

#include "headers.h"

static void load_intro_music(cn_t *cn)
{
    play_music(cn, "res/snd/sfx/intro.ogg", 0);
}

static void end_intro(cn_t *cn, sfClock *clock)
{
    sfClock_destroy(clock);
    free_objs(cn);
}

static void update_scene(cn_t *cn, float time, obj_fun_t *logo)
{
    if (time > 2.0f)
        logo->pos.z = 0.0f;
    if ((time > 3.0f) && (!cn->render.is_dithering))
        set_dithering(cn, 1, 1.0f);
}

int intro(cn_t *cn)
{
    sfClock *clock = sfClock_create();
    float time;
    obj_fun_t *fun = add_obj_fun(cn, (vec3){-0.8, -0.45f, -2.0f},
    (vec2){1.6f, 0.9f}, cn->sprite[S_GAX]);

    load_intro_music(cn);
    do {
        if (!poll_events(cn)) {
            end_intro(cn, clock);
            return (0);
        }
        time = sfTime_asSeconds(sfClock_getElapsedTime(cn->render.clock));
        update_scene(cn, time, fun);
        render(cn);
    } while (time < 4.0f);
    end_intro(cn, clock);
    return (1);
}
