/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _ENNEMY_STRUCT_H
#define _ENNEMY_STRUCT_H

#define FLAME_COUNT 192
#define FLAME_LAYERS 32
#define FLAME_SPACING 4.0f

typedef struct {
    obj_fun_t *obj[FLAME_LAYERS][FLAME_COUNT];
    obj_fun_t *flame_obj[FLAME_LAYERS];
    vec3 pos;
    vec3 speed;
} flame_ocean_t;

#endif
