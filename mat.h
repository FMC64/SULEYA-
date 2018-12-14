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

void trans_mul(sfTransform *op, sfTransform *base);

#endif
