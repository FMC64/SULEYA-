/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _DATA_H
#define _DATA_H

#include "mat.h"
#include "sprite.h"
#include "obj_struct.h"
#include "input_struct.h"

typedef struct {
    uint32_t w;
    uint32_t h;
    float whalf;
    float hhalf;
    float framerate;
    float framelen;
    sfRenderWindow *window;
    sfClock *clock;
    uint64_t frame;
} win_t;

typedef struct {
    vec3 pos;
    vec3 speed;
    float maxsx;
    vec2 size;
    int is_grounded;
    sprite_t *sprite;
} player_t;

typedef struct {
    vec3 pos;
    vec3 shift;
    float ratiowh;
    float fovw;
} cam_t;

typedef struct {
    win_t win;
    objs_t objs;
    cam_t cam;
    player_t player;
    input_t input;
} cn_t;

typedef sfRenderStates sfrenderstate_t;

#endif
