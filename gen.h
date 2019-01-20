/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** generation !
*/

#ifndef _GEN_H
#define _GEN_H

obj_fun_t* gen_ter(cn_t *cn, vec3 lastpos, vec2 lastsize, sprite_t *sprite);
void gen_pub(cn_t *cn, sprite_t *bendy, sprite_t *tree, vec3 pos);
obj_fun_t* gen_sky(cn_t *cn, obj_fun_t *last, sprite_t *sky);

#endif
