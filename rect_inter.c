/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** rectangle intersection
*/

#include "headers.h"

void get_rect_points(rect_t rect, vec2 *res)
{
    res[0] = (vec2){rect.x, rect.y};
    res[1] = (vec2){rect.x + rect.w, rect.y};
    res[2] = (vec2){rect.x + rect.w, rect.y + rect.h};
    res[3] = (vec2){rect.x, rect.y + rect.h};
}

int is_point_in_rect(rect_t rect, vec2 point)
{
    return ((point.x >= rect.x) && (point.x < (rect.x + rect.w)) &&
    (point.y >= rect.y) && (point.y < (rect.y + rect.h)));
}

int rect_inter(rect_t a, rect_t b)
{
    vec2 point[4];

    get_rect_points(a, point);
    for (size_t i = 0; i < 4; i++)
        if (is_point_in_rect(b, point[i]))
            return (1);
    get_rect_points(b, point);
    for (size_t i = 0; i < 4; i++)
        if (is_point_in_rect(a, point[i]))
            return (1);
    return (0);
}
