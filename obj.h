/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _OBJ_H
#define _OBJ_H

typedef enum {
OBJ_TILEMAP,
OBJ_FUN
} obj_type_t;

typedef struct {
obj_type_t type;
void *data;
} obj_t;

typedef struct {
size_t count;
size_t allocated;
obj_t *obj;
} objs_t;

typedef struct {
vec3 pos;
size_t w;
size_t h;
uint32_t *data;
} obj_tilemap_t;

#endif
