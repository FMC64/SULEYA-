/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** generation !
*/

#ifndef _GEN_H
#define _GEN_H

void gen_next(cn_t *cn);
void gen_depot(cn_t *cn);

void gen_depot_bg(cn_t *cn);
void gen_depot_bridge_cables(cn_t *cn, vec3 pos, vec2 size);

void gen_depot_box(cn_t *cn, vec3 pos, vec2 size);

#endif
