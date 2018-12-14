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

sprite_t* create_sprite(const char *path);
void destroy_sprite(sprite_t *sprite);

#endif
