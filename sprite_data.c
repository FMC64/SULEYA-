
/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** sprite things
*/

#include "headers.h"

static const sprite_data_descriptor_t sprite_data[] = {
    {S_TREE, "res/tree.png"},
    {S_PEBBLES_MOD, "res/pebbles.jpg"},
    {S_PEBBLES_MOD_HALF, "res/pebbles_mod.png"},
    {S_SKY, "res/sky.png"},
    {S_BENDY, "res/bendy_blurred.png"},
    {S_GRADIENT, "res/misc/gradient.png"},
    {S_GAX, "res/misc/gax.png"},
    {S_BASHO_MENU, "res/menu/basho.png"},
    {S_MENU_TITLE, "res/menu/title.png"},
    {S_MENU_BG, "res/menu/bg.jpg"},
    {S_MENU_ASTEROID, "res/menu/asteroid.png"},
    {S_MENU_BG2, "res/menu/bg2.png"},
    {S_MENU_INC_BASHO, "res/menu/inc_basho.png"},
    {S_MENU_PRO_HINT, "res/menu/pro_hint.png"},
    {0, NULL}
};

static const sprite_anim_data_descriptor_t sprite_anim_data[] = {
    {S_BASHO_RUN, "res/anim/basho_run/sheet.png", 3, 0.1f},
    {S_BASHO_RUN_L, "res/anim/basho_run/sheet_l.png", 3, 0.1f},
    {S_BASHO_IDLE, "res/anim/basho_idle/sheet.png", 2, 2.0f},
    {S_BASHO_IDLE_L, "res/anim/basho_idle/sheet_l.png", 2, 2.0f},
    {S_BASHO_AIR, "res/anim/basho_air/sheet.png", 4, 0.1f},
    {S_BASHO_AIR_L, "res/anim/basho_air/sheet_l.png", 4, 0.1f},
    {S_BASHO_PUNCH, "res/anim/basho_punch/sheet.png", 6, 0.05f},
    {S_BASHO_PUNCH_L, "res/anim/basho_punch/sheet_l.png", 6, 0.05f},
    {0, NULL, 0, 0.0f}
};

void load_sprites(cn_t *cn)
{
    for (size_t i = 0; i < S_MAX; i++)
        cn->sprite[i] = NULL;
    for (size_t i = 0; sprite_data[i].path != NULL; i++)
        cn->sprite[sprite_data[i].index] = create_sprite(sprite_data[i].path);
    for (size_t i = 0; sprite_anim_data[i].path != NULL; i++) {
        cn->sprite[sprite_anim_data[i].index] =
        create_sprite(sprite_anim_data[i].path);
        cn->sprite[sprite_anim_data[i].index]->framecount =
        sprite_anim_data[i].framecount;
        cn->sprite[sprite_anim_data[i].index]->framelen =
        sprite_anim_data[i].framelen;
        cn->sprite[sprite_anim_data[i].index]->clock = sfClock_create();
        sfClock_restart(cn->sprite[sprite_anim_data[i].index]->clock);
    }
}

void unload_sprites(cn_t *cn)
{
    for (size_t i = 0; i < S_MAX; i++)
        if (cn->sprite[i] != NULL)
            destroy_sprite(cn->sprite[i]);
}

static void update_sprite(sprite_t *sprite)
{
    sfIntRect rectangle = {0, 0, 0, 0};
    uint32_t frame;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(sprite->clock));

    frame = fmodf(time, sprite->framelen * (float)sprite->framecount) /
    sprite->framelen;
    if (frame == sprite->frame)
        return;
    sprite->frame = frame;
    sprite->w = sprite->truew / sprite->framecount;
    rectangle.left = frame * sprite->w;
    rectangle.width = sprite->w;
    rectangle.height = sprite->h;
    sfSprite_setTextureRect(sprite->sprite, rectangle);
    if (sfTime_asSeconds(sfClock_getElapsedTime(sprite->clock)) > 128.0f)
        sfClock_restart(sprite->clock);
}

void update_sprites_frame(cn_t *cn)
{
    for (size_t i = 0; i < S_MAX; i++)
        if (cn->sprite[i]->clock != NULL)
            update_sprite(cn->sprite[i]);
}
