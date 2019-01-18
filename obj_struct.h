/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _OBJ_STRUCT_H
#define _OBJ_STRUCT_H

typedef enum {
    OBJ_TILEMAP,
    OBJ_FUN
} obj_type_t;

typedef struct {
    uint64_t count;
    vec2 vertex[5];
    vec2 norm[4];
} mesh_t;

typedef struct {
    obj_type_t type;
    void *data;
} obj_t;

typedef struct {
    float z;
    uint64_t count;
    uint64_t allocated;
    obj_t *obj;
} objset_t;

typedef struct {
    uint64_t count;
    uint64_t allocated;
    objset_t *set;
} objs_t;

typedef struct {
    vec3 pos;
    size_t w;
    size_t h;
    float size;
    uint64_t layer_count;
    uint32_t **layer;
    uint32_t *collider;
    spritesheet_t *sheet;
} obj_tilemap_t;

typedef struct {
    int is_collider;
    int is_static;
    int is_grounded;
    int is_destroyable;
    int is_sprite_linked;
    float friction;
    float bounce;
    mesh_t mesh;
    vec3 pos;
    vec3 speed;
    vec2 size;
    sprite_t *sprite;
    float life;
    sfClock *clock;
} obj_fun_t;

typedef struct {
    uint64_t count;
    rect_t rect[128];
} split_rects_t;

#endif
