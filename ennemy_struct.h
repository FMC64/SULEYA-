/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _ENNEMY_STRUCT_H
#define _ENNEMY_STRUCT_H

#define FLAME_COUNT 128

typedef struct {
    obj_fun_t *obj[FLAME_COUNT];
    obj_fun_t *flame_obj;
    vec3 pos;
    vec3 speed;
} flame_ocean_t;

#endif
