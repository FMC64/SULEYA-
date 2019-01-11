/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _MAT_H
#define _MAT_H

#define MAX_COLS 512

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

typedef struct {
    float dist;
    vec2 to_add;
} phys_col_t;

typedef struct {
    uint64_t count;
    phys_col_t col[MAX_COLS];
} phys_cols_t;

void trans_mul(sfTransform *op, sfTransform *base);

vec2 vec2_add(vec2 a, vec2 b);
vec2 vec2_sub(vec2 a, vec2 b);

float vec2_dot(vec2 a, vec2 b);
float dist2_sq(vec2 a, vec2 b);

void inter2d(seg2 a, seg2 b, float *ta, float *tb);
vec2 seg2_interp(seg2 seg2, float ratio);
float ray2d(seg2 ray, seg2 b);
int is_point_in_rec(vec2 p, vec2 rp, vec2 rs);

#endif
