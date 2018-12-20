/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** spritesheet things
*/

#include "headers.h"

spritesheet_t* create_spritesheet(sprite_t *sprite, size_t sprite_size)
{
    spritesheet_t *res = (spritesheet_t*)malloc_safe(sizeof(spritesheet_t));

    res->sprite = sprite;
    res->size = sprite_size;
    res->w = sprite->w / sprite_size;
    res->h = sprite->h / sprite_size;
    return (res);
}

void destroy_spritesheet(spritesheet_t *spritesheet)
{
    free(spritesheet);
}
