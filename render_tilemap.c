/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

static void render_layers_tilemap(cn_t *cn, obj_tilemap_t *tilemap,
size_t i, size_t j)
{
    float x = tilemap->pos.x - cn->cam.pos.x;
    float y = tilemap->pos.y - cn->cam.pos.y;
    float z = tilemap->pos.z - cn->cam.pos.z;
    float w;
    float h;
    uint32_t tile;

    if (z <= 0.0f)
        return;
    w = (tilemap->size / z) * (cn->win.whalf / (float)tilemap->sheet->size);
    h = (tilemap->size / z) * (cn->win.whalf / (float)tilemap->sheet->size);
    for (size_t k = 0; k < tilemap->layer_count; k++) {
        tile = tilemap->layer[k][i * tilemap->w + j];
        render_sprite(cn, tilemap->sheet->sprite, RENDER_TILEMAP_RECT,
        &(sfTransform){{w, 0.0f, ((x + (float)j * tilemap->size) / z)
        * cn->win.whalf + cn->win.whalf, 0.0f, h,
        ((y + (float)i * tilemap->size) / z) * cn->win.whalf
        + cn->win.hhalf, 0.0f, 0.0f, 1.0f}});
    }
}

void render_tilemap(cn_t *cn, obj_tilemap_t *tilemap)
{
    for (size_t i = 0; i < tilemap->h; i++)
        for (size_t j = 0; j < tilemap->w; j++)
            render_layers_tilemap(cn, tilemap, i, j);
}
