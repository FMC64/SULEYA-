/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

void inter2d(seg2 a, seg2 b, float *ta, float *tb)
{
    float div = (b.p[1].x - b.p[0].x) * (a.p[0].y - a.p[1].y) -
    (a.p[0].x - a.p[1].x) * (b.p[1].y - b.p[0].y);

    if (div == 0.0f) {
        *ta = 0.0f;
        *tb = 0.0f;
    }
    *ta = ((b.p[0].y - b.p[1].y) * (a.p[0].x - b.p[0].x) +
    (b.p[1].x - b.p[0].x) * (a.p[0].y - b.p[0].y)) / div;
    *tb = ((a.p[0].y - a.p[1].y) * (a.p[0].x - b.p[0].x) +
    (a.p[1].x - a.p[0].x) * (a.p[0].y - b.p[0].y)) / div;
}

float ray2d(seg2 ray, seg2 b)
{
    float div = (b.p[1].x - b.p[0].x) * (ray.p[0].y - ray.p[1].y) -
    (ray.p[0].x - ray.p[1].x) * (b.p[1].y - b.p[0].y);

    if (div == 0.0f)
        return (0.0f);
    return (((ray.p[0].y - ray.p[1].y) * (ray.p[0].x - b.p[0].x) +
    (ray.p[1].x - ray.p[0].x) * (ray.p[0].y - b.p[0].y)) / div);
}

int is_point_in_rec(vec2 p, vec2 rp, vec2 rs)
{
    return ((p.x >= rp.x) && (p.x < (rp.x + rs.x)) &&
    (p.y >= rp.y) && (p.y < (rp.y + rs.y)));
}
