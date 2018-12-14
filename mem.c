/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** sprite things
*/

#include "headers.h"

void memcpy_custom(void *src, void *dst, size_t size)
{
    uint8_t *src_ac = src;
    uint8_t *dst_ac = dst;

    for (size_t i = 0; i < size; i++)
        dst_ac[i] = src_ac[i];
}
