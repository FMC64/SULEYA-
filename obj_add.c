/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj insertion
*/

#include "headers.h"

static void obj_fun_init_bools(obj_fun_t *fun)
{
    fun->is_collider = 1;
    fun->is_static = 1;
    fun->is_grounded = 0;
    fun->last_grounded = ~0ULL;
    fun->is_destroyable = 0;
    fun->is_sprite_linked = 0;
}

obj_fun_t* add_obj_fun(cn_t *cn, vec3 pos, vec2 size, sprite_t *sprite)
{
    obj_fun_t *to_add = (obj_fun_t*)malloc_safe(sizeof(obj_fun_t));
    obj_t *cur = get_obj_slot(cn, pos.z);

    obj_fun_init_bools(to_add);
    to_add->friction = 20.0f;
    to_add->bounce = 1.2f;
    to_add->mesh = (mesh_t){4, {{0.0f, 0.0f}, {size.x, 0.0f}, {size.x, size.y},
    {0.0f, size.y}}, {{0.0f, -1.0f}, {1.0f, 0.0f}, {0.0f, 1.0f},
    {-1.0f, 0.0f}}};
    to_add->pos = pos;
    to_add->speed = (vec3){0.0f, 0.0f, 0.0f};
    to_add->size = size;
    to_add->sprite = sprite;
    to_add->life = 0.0f;
    to_add->clock = NULL;
    cur->type = OBJ_FUN;
    cur->data = to_add;
    return (to_add);
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
