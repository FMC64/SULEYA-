/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _DATA_H
#define _DATA_H

#include "mat.h"
#include "sprite_struct.h"
#include "obj_struct.h"
#include "input_struct.h"

typedef enum {
    PLAYER_REG,
    PLAYER_PUNCHING
} player_state_t;

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
    float maxsx;
    int is_right;
    int is_moving;
    player_state_t state;
    int has_punched;
    sfClock *clock;
    obj_fun_t *fun;
} player_t;

typedef struct {
    vec3 pos;
    vec3 shift;
    float ratiowh;
    float fovw;
} cam_t;

typedef struct {
    int is_dithering;
    int dither_is_fading;
    float dithering_laps;
    int is_dither_done;
    sfClock *clock;
} render_t;

typedef struct {
    win_t win;
    objs_t objs;
    cam_t cam;
    player_t player;
    input_t input;
    sprite_t *sprite[S_MAX];
    render_t render;
} cn_t;

typedef sfRenderStates sfrenderstate_t;

#endif
