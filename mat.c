/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

static float trans_mul_iter(sfTransform *op, sfTransform *base,
size_t i, size_t j)
{
    float sum = 0.0f;

    for (size_t k = 0; k < 3; k++)
        sum += op->matrix[i * 3 + k] * base->matrix[k * 3 + j];
    return (sum);
}

void trans_mul(sfTransform *op, sfTransform *base)
{
    sfTransform res;

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            res.matrix[i * 3 + j] = trans_mul_iter(op, base, i, j);
    *base = res;
}

float vec2_dot(vec2 a, vec2 b)
{
    return (a.x * b.x + a.y * a.y);
}

float dist2_sq(vec2 a, vec2 b)
{
    vec2 vec = {b.x - a.x, b.y - a.y};

    return (vec.x * vec.x + vec.y * vec.y);
}
