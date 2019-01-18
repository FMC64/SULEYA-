/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj insertion
*/

#include "headers.h"

void destroy_obj(objset_t *set, uint64_t i)
{
    free_obj(&set->obj[i]);
    if (set->count == 0)
        return;
    set->count--;
    set->obj[i] = set->obj[set->count];
}
