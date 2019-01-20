/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _SPRITE_STRUCT_H
#define _SPRITE_STRUCT_H

typedef enum {
    S_BASHO_RUN,
    S_BASHO_RUN_L,
    S_BASHO_IDLE,
    S_BASHO_IDLE_L,
    S_BASHO_AIR,
    S_BASHO_AIR_L,
    S_BASHO_PUNCH,
    S_BASHO_PUNCH_L,
    S_TREE,
    S_PEBBLES_MOD,
    S_PEBBLES_MOD_HALF,
    S_SKY,
    S_BENDY,
    S_GRADIENT,
    S_GAX,
    S_BASHO_MENU,
    S_MENU_TITLE,
    S_MENU_BG,
    S_MENU_ASTEROID,
    S_MENU_BG2,
    S_MENU_INC_BASHO,
    S_MENU_PRO_HINT,
    S_FLAME_ANIM,
    S_FLAME,
    S_FONT_SFAMICOM,
    S_GAMEOVER,
    S_GAMEOVER_WIN,
    S_MAX
} sprite_data_t;

typedef struct {
    size_t truew;
    size_t w;
    size_t h;
    sfSprite *sprite;
    sfTexture *texture;
    uint32_t frame;
    uint32_t framecount;
    float framelen;
    sfClock *clock;
} sprite_t;

typedef struct {
    sprite_t *sprite;
    size_t size;
    size_t w;
    size_t h;
} spritesheet_t;

typedef struct {
    sprite_data_t index;
    const char *path;
} sprite_data_descriptor_t;

typedef struct {
    sprite_data_t index;
    const char *path;
    uint32_t framecount;
    float framelen;
} sprite_anim_data_descriptor_t;

#endif
