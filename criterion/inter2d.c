/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** inter2d tests
*/

#include "headers.h"

#include <criterion/criterion.h>

Test(inter2d, base)
{
    seg2 a = {{{2.0f, 3.0f}, {6.0f, 1.0f}}};
    seg2 b = {{{2.0f, 2.0f}, {5.0f, 3.0f}}};
    float ta;
    float tb;

    inter2d(a, b, &ta, &tb);
    printf("%f, %f\n%f, %f",
    a.p[0].x + ta * (a.p[1].x - a.p[0].x),
    a.p[0].y + ta * (a.p[1].y - a.p[0].y));
}
