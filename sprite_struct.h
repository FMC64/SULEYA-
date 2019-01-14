/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _SPRITE_STRUCT_H
#define _SPRITE_STRUCT_H

typedef struct {
    size_t w;
    size_t h;
    sfSprite *sprite;
    sfTexture *texture;
    uint32_t frame;
    uint32_t framecount;
    float framelen;
} sprite_t;

typedef struct {
    sprite_t *sprite;
    size_t size;
    size_t w;
    size_t h;
} spritesheet_t;

typedef enum {
    S_BASHO,
    S_TREE,
    S_PEBBLES_MOD,
    S_SKY,
    S_BENDY,
    S_MAX
} sprite_data_t;

typedef struct {
    sprite_data_t index;
    const char *path;
} sprite_data_descriptor_t;

#endif
