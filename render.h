/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#ifndef _RENDER_H
#define _RENDER_H

#include "headers.h"

#define RENDER_SLOTS (1ULL << 20ULL)

sfRenderStates get_default_render_states(void);
void render_tilemap(cn_t *cn, obj_tilemap_t *tilemap);

void init_render_buf(void);
void render_sprite(cn_t *cn, sprite_t *sprite, sfIntRect *rectangle,
sfTransform *trans);

void render(cn_t *cn);
void render_present(cn_t *cn);

void render_fun(cn_t *cn, obj_fun_t *fun);
void render_tilemap(cn_t *cn, obj_tilemap_t *tilemap);

void update_framerate(cn_t *cn);

#endif
