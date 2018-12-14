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

#include "obj.h"

typedef struct {
uint32_t w;
uint32_t h;
float framerate;
float framelen;
sfRenderWindow *window;
} win_t;

typedef struct {
vec3 pos;
float fovw;
} cam_t;

typedef struct {
win_t win;
objs_t objs;
cam_t cam;
} cn_t;

#endif
