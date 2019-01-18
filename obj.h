/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _OBJ_H
#define _OBJ_H

#define LAYER_COUNT 5

#define OBJ_ALLOC_STEP 64

obj_t* get_obj_slot(cn_t *cn, float z);

obj_fun_t* add_obj_fun(cn_t *cn, vec3 pos, vec2 size, sprite_t *sprite);
obj_t* add_obj_tilemap(cn_t *cn, vec3 pos, size_t w, size_t h);

uint32_t* obj_tilemap_add_layer(obj_t *obj);
void obj_tilemap_set_sheet(obj_t *obj, spritesheet_t *sheet);

void destroy_obj(objset_t *set, uint64_t index);

void free_obj_fun(obj_fun_t *fun);
void obj_fun_set_life(obj_fun_t *fun, float life);

void free_obj_tilemap(obj_tilemap_t *tilemap);

void free_obj(obj_t *obj);
void free_objs(cn_t *cn);

void update_objs(cn_t *cn);

void gen_split_rec(uint64_t count, split_rects_t *rects,
uint64_t to_split);
void split_obj(cn_t *cn, objset_t *set, uint64_t i, vec2 impulse);

#endif
