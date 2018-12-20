/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj insertion
*/

#include "headers.h"

void free_obj_tilemap(obj_tilemap_t *tilemap)
{
    for (size_t i = 0; i < tilemap->layer_count; i++)
        free(tilemap->layer[i]);
    free(tilemap->layer);
    free(tilemap->collider);
    free(tilemap);
}
