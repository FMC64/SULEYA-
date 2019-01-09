/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _MAT_H
#define _MAT_H

typedef struct {
    float x;
    float y;
    float z;
} vec3;

typedef struct {
    float x;
    float y;
} vec2;

typedef struct {
    vec2 p[2];
} seg2;

void trans_mul(sfTransform *op, sfTransform *base);

float vec2_dot(vec2 a, vec2 b);

void inter2d(seg2 a, seg2 b, float *ta, float *tb);
float ray2d(seg2 ray, seg2 b);
int is_point_in_rec(vec2 p, vec2 rp, vec2 rs);

#endif
