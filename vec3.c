/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

vec3 vec3_add(vec3 a, vec3 b)
{
    return ((vec3){a.x + b.x, a.y + b.y, a.z + b.z});
}

vec3 vec3_sub(vec3 a, vec3 b)
{
    return ((vec3){a.x - b.x, a.y - b.y, a.z - b.z});
}
