/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

sfrenderstate_t get_default_render_states(void)
{
    sfRenderStates res;

    res.blendMode = sfBlendAlpha;
    res.transform = sfTransform_Identity;
    res.texture = NULL;
    res.shader = NULL;
    return (res);
}

static void render_obj(cn_t *cn, obj_t *obj)
{
    switch (obj->type) {
    case OBJ_FUN:
        render_fun(cn, obj->data);
        break;
    case OBJ_TILEMAP:
        render_tilemap(cn, obj->data);
        break;
    default:
        break;
    }
}

static void render_fading(cn_t *cn)
{
    float time;
    float ratio;

    if (!cn->render.is_dithering)
        return;
    time = sfTime_asSeconds(sfClock_getElapsedTime(cn->render.clock));
    if (time > cn->render.dithering_laps) {
        cn->render.is_dither_done = 1;
        if (!cn->render.dither_is_fading)
            return;
        render_sprite(cn, cn->sprite[S_GRADIENT], &(sfIntRect){255, 0, 1, 1},
        &(sfTransform){{cn->win.w, 0.0f, 0.0f, 0.0f, cn->win.h, 0.0f,
        0.0f, 0.0f, 1.0f}});
    }
    ratio = time / cn->render.dithering_laps;
    if (!cn->render.dither_is_fading)
        ratio = 1.0f - ratio;
    render_sprite(cn, cn->sprite[S_GRADIENT], &(sfIntRect){ratio * 255.0f,
    0, 1, 1}, &(sfTransform){{cn->win.w, 0.0f, 0.0f, 0.0f, cn->win.h, 0.0f,
    0.0f, 0.0f, 1.0f}});
}

void render_draw(cn_t *cn)
{
    for (size_t i = 0; i < cn->objs.count; i++)
        for (size_t j = 0; j < cn->objs.set[i].count; j++)
            render_obj(cn, &cn->objs.set[i].obj[j]);
    if (cn->misc.is_gameover) {
        render_sprite(cn, cn->sprite[cn->misc.has_won ?
        S_GAMEOVER_WIN : S_GAMEOVER], NULL, &(sfTransform){{(float)cn->win.w /
        (float)cn->sprite[S_GAMEOVER]->w, 0.0f, 0.0f, 0.0f, (float)cn->win.h /
        (float)cn->sprite[S_GAMEOVER]->h, 0.0f, 0.0f, 0.0f, 1.0f}});
        render_highscore(cn);
    }
    if (cn->render.render_score)
        render_score(cn);
    render_fading(cn);
}

void render(cn_t *cn)
{
    sfRenderWindow_clear(cn->win.window, sfBlack);
    render_draw(cn);
    render_present(cn);
    update_framerate(cn);
}
