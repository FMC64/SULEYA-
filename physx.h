/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#ifndef _PHYSX_H
#define _PHYSX_H

void physx(cn_t *cn);
void add_phys_col(vec2 to_add, vec2 *acc);

vec2 get_p_norm(size_t i);
vec2 get_fun_norm(seg2 seg);
void phys_fun(cn_t *cn, obj_fun_t *fun, vec2 *vec);

void phys_fun_funtop(vec2 *point, vec2 to_ext, vec2 *vec);

void phys_is_grounded(cn_t *cn);

#endif
