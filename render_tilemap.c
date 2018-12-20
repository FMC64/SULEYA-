/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

void render_sprite_tilemap(cn_t *cn, obj_tilemap_t *tilemap,
size_t i, size_t j)
{
    float x = tilemap->pos.x - cn->cam.pos.x;
    float y = tilemap->pos.y - cn->cam.pos.y;
    float z = tilemap->pos.z - cn->cam.pos.z;
    float w;
    float h;

    if (z <= 0.0f)
        return;
    w = (tilemap->size / z) * ((float)(cn->win.w / 2) /
    (float)tilemap->sheet->size);
    h = (tilemap->size / z) * ((float)(cn->win.w / 2) /
    (float)tilemap->sheet->size);
    y -= h * (float)tilemap->sheet->size;
    for (size_t k = 0; k < tilemap->layer_count; k++) {
        render_sprite(cn, tilemap->sheet->sprite,
        &(sfIntRect){j * tilemap->sheet->size, i * tilemap->sheet->size,
        tilemap->sheet->size, tilemap->sheet->size},
        &(sfTransform){{w, 0.0f, ((x + (float)j * tilemap->size) / z)
        * (float)(cn->win.w / 2) + (float)(cn->win.w / 2), 0.0f, h,
        (-(y + (float)i * tilemap->size) / z) * (float)(cn->win.w / 2)
        + (float)(cn->win.h / 2), 0.0f, 0.0f, 1.0f}});
    }
}

void render_tilemap(cn_t *cn, obj_tilemap_t *tilemap)
{
    (void)cn;
    for (size_t i = 0; i < tilemap->h; i++)
        for (size_t j = 0; j < tilemap->w; j++)
            render_sprite_tilemap(cn, tilemap, i, j);
}
