/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _SPRITE_H
#define _SPRITE_H

typedef struct {
    size_t w;
    size_t h;
    uint32_t *data;
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct {
    sprite_t *sprite;
    size_t size;
    size_t w;
    size_t h;
} spritesheet_t;

sprite_t* create_sprite(const char *path);
void destroy_sprite(sprite_t *sprite);

spritesheet_t* create_spritesheet(const char *path, size_t sprite_size);
void destroy_spritesheet(spritesheet_t *spritesheet);

#endif
