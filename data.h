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
float framerate;
float framelen;
sfRenderWindow *window;
} win_t;

typedef struct {
vec3 pos;
float ratiowh;
float fovw;
} cam_t;

typedef struct {
win_t win;
objs_t objs;
cam_t cam;
input_t input;
} cn_t;

#endif
