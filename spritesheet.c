/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** spritesheet things
*/

#include "headers.h"

spritesheet_t* create_spritesheet(const char *path, size_t sprite_size)
{
    spritesheet_t *res = (spritesheet_t*)malloc_safe(sizeof(spritesheet_t));

    res->sprite = create_sprite(path);
    res->size = sprite_size;
    res->w = res->sprite->w / sprite_size;
    res->h = res->sprite->h / sprite_size;
    return (res);
}

void destroy_spritesheet(spritesheet_t *spritesheet)
{
    destroy_sprite(spritesheet->sprite);
    free(spritesheet);
}
