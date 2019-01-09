/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj insertion
*/

#include "headers.h"

obj_t* add_obj_fun(cn_t *cn, vec3 pos, vec2 size, sprite_t *sprite)
{
    obj_fun_t *to_add = (obj_fun_t*)malloc_safe(sizeof(obj_fun_t));
    obj_t *cur = get_obj_slot(cn, pos.z);

    to_add->is_collider = 1;
    to_add->pos = pos;
    to_add->size = size;
    to_add->sprite = sprite;
    cur->type = OBJ_FUN;
    cur->data = to_add;
    return (cur);
}

obj_t* add_obj_tilemap(cn_t *cn, vec3 pos, size_t w, size_t h)
{
    obj_tilemap_t *to_add = (obj_tilemap_t*)malloc_safe(sizeof(obj_tilemap_t));
    obj_t *cur = get_obj_slot(cn, pos.z);

    to_add->pos = pos;
    to_add->w = w;
    to_add->h = h;
    to_add->size = 1.0f;
    to_add->layer_count = 0;
    to_add->layer = NULL;
    to_add->collider = (uint32_t*)malloc_safe(sizeof(uint32_t) * w * h);
    to_add->sheet = NULL;
    cur->type = OBJ_TILEMAP;
    cur->data = to_add;
    return (cur);
}

uint32_t* obj_tilemap_add_layer(obj_t *obj)
{
    obj_tilemap_t *map = obj->data;
    uint64_t cur = map->layer_count++;
    uint32_t **new_layer =
    (uint32_t**)malloc_safe(sizeof(uint32_t*) * map->layer_count);

    for (size_t i = 0; i < cur; i++)
        new_layer[i] = map->layer[i];
    free(map->layer);
    map->layer = new_layer;
    return (map->layer[cur] =
    (uint32_t*)malloc_safe(sizeof(uint32_t) * map->w * map->h));
}

void obj_tilemap_set_sheet(obj_t *obj, spritesheet_t *sheet)
{
    obj_tilemap_t *map = obj->data;

    map->sheet = sheet;
}
