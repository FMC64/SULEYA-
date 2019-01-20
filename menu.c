/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** menu
*/

#include "headers.h"

static void load_menu_music(cn_t *cn)
{
    play_music(cn,
    "res/snd/music/sid_sound-1dB의 마법.ogg", 1);
}

static void end_menu(cn_t *cn, sfClock *clock)
{
    stop_music(cn);
    sfClock_destroy(clock);
    free_objs(cn);
}

static void update_scene(cn_t *cn, float time, obj_fun_t *inc_basho)
{
    cn->cam.pos.z = -1.0f + (sinf(time / 4.0f) + 1.0f) / 32.0f;
    sfSprite_setRotation(inc_basho->sprite->sprite, time * 4.0f);
}

static void load_menu_stuff(cn_t *cn, obj_fun_t **inc_basho)
{
    add_obj_fun(cn, (vec3){0.5f, -0.5f, 0.0f},
    (vec2){1.69f * 0.3f, 4.99f * 0.3f}, cn->sprite[S_BASHO_MENU]);
    add_obj_fun(cn, (vec3){-0.5f, -0.35f, -0.25f},
    (vec2){1.024f * 0.8f, 0.384f * 0.8f}, cn->sprite[S_MENU_TITLE]);
    add_obj_fun(cn, (vec3){-60.0f, -30.0f, 50.0f},
    (vec2){7.80f * 15.0f, 4.56f * 15.0f}, cn->sprite[S_MENU_BG]);
    add_obj_fun(cn, (vec3){-2.0f, -0.2f, 1.0f},
    (vec2){6.20f * 0.7f, 3.10f * 0.7f}, cn->sprite[S_MENU_ASTEROID]);
    add_obj_fun(cn, (vec3){-3.0f, -1.0f, 0.0f},
    (vec2){1.6f * 3.0f, 0.9f * 3.0f}, cn->sprite[S_MENU_BG2]);
    *inc_basho = add_obj_fun(cn, (vec3){1.0f, 0.3f, -0.2f},
    (vec2){2.0f, 2.0f}, cn->sprite[S_MENU_INC_BASHO]);
    sfSprite_setOrigin(cn->sprite[S_MENU_INC_BASHO]->sprite,
    (sfVector2f){512.0f, 512.0f});
    add_obj_fun(cn, (vec3){-0.9f, 0.01f, -0.1f},
    (vec2){0.5f, 0.5f}, cn->sprite[S_MENU_PRO_HINT]);
    set_dithering(cn, 0, 1.0f);
}

int menu(cn_t *cn)
{
    sfClock *clock = sfClock_create();
    float time;
    obj_fun_t *inc_basho;

    load_menu_music(cn);
    load_menu_stuff(cn, &inc_basho);
    while (menu_input(cn)) {
        if (!poll_events(cn)) {
            end_menu(cn, clock);
            return (0);
        }
        time = sfTime_asSeconds(sfClock_getElapsedTime(cn->render.clock));
        update_scene(cn, time, inc_basho);
        render(cn);
    }
    end_menu(cn, clock);
    return (1);
}
