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

typedef struct {
    vec2 p;
    float bounce;
} p_in_geom_t;

typedef struct {
    float x;
    float y;
    float w;
    float h;
} rect_t;

void trans_mul(sfTransform *op, sfTransform *base);

vec2 vec2_add(vec2 a, vec2 b);
vec2 vec2_sub(vec2 a, vec2 b);
vec2 vec2_normalize(vec2 vec);

vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_sub(vec3 a, vec3 b);

float vec2_dot(vec2 a, vec2 b);
float dist2_sq(vec2 a, vec2 b);
float dist3(vec3 vec);

void inter2d(seg2 a, seg2 b, float *ta, float *tb);
vec2 seg2_interp(seg2 seg2, float ratio);
float ray2d(seg2 ray, seg2 b);
int is_point_in_rec(vec2 p, vec2 rp, vec2 rs);

void get_rect_points(rect_t rect, vec2 *res);
int is_point_in_rect(rect_t rect, vec2 point);
int rect_inter(rect_t a, rect_t b);

float dist3_sq(vec3 vec);

#endif
