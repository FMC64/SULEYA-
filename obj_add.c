/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj insertion
*/

#include "headers.h"

obj_t* add_obj_fun(cn_t *cn, vec3 pos, vec2 size, sprite_t *sprite)
{
    obj_fun_t *to_add = (obj_fun_t*)malloc_safe(sizeof(obj_fun_t));
    obj_t *cur = get_obj_slot(cn, pos.z);

    to_add->pos = pos;
    to_add->size = size;
    to_add->sprite = sprite;
    cur->type = OBJ_FUN;
    cur->data = to_add;
    return (cur);
}
