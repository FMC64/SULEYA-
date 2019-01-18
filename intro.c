/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** intro
*/

#include "headers.h"

static sfMusic* load_intro_music(void)
{
    sfMusic *res = sfMusic_createFromFile("res/snd/intro.ogg");

    if (res == NULL)
        exit_full_custom();
    sfMusic_play(res);
    return (res);
}

static void end_intro(cn_t *cn, sfMusic *music, sfClock *clock)
{
    sfMusic_stop(music);
    sfMusic_destroy(music);
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
    sfMusic *music;
    float time;
    obj_fun_t *fun = add_obj_fun(cn, (vec3){-0.8, -0.45f, -2.0f},
    (vec2){1.6f, 0.9f}, cn->sprite[S_GAX]);

    music = load_intro_music();
    do {
        if (!poll_events(cn)) {
            end_intro(cn, music, clock);
            return (0);
        }
        time = sfTime_asSeconds(sfClock_getElapsedTime(cn->render.clock));
        update_scene(cn, time, fun);
        render(cn);
    } while (time < 4.0f);
    end_intro(cn, music, clock);
    return (1);
}
