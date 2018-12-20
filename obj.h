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

obj_t* add_obj_fun(cn_t *cn, vec3 pos, vec2 size, sprite_t *sprite);

void free_obj_fun(obj_fun_t *fun);
void free_obj_tilemap(obj_tilemap_t *tilemap);

void free_obj(obj_t *obj);
void free_objs(cn_t *cn);

#endif
