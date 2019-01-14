/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** sprite things
*/

#include "headers.h"

static const sprite_data_descriptor_t sprite_data[] = {
    {S_BASHO, "res/basho.jpg"},
    {S_TREE, "res/tree.png"},
    {S_PEBBLES_MOD, "res/pebbles_mod.png"},
    {S_SKY, "res/sky.png"},
    {S_BENDY, "res/bendy_blurred.png"},
    {0, NULL}
};

void load_sprites(cn_t *cn)
{
    for (size_t i = 0; i < S_MAX; i++)
        cn->s.sprite[i] = NULL;
    for (size_t i = 0; sprite_data[i].path != NULL; i++)
        cn->s.sprite[sprite_data[i].index] = create_sprite(sprite_data[i].path);
    //cn->s.sprite[S_BASHO]->framecount = 3;
    //cn->s.sprite[S_BASHO]->framelen = 0.2f;
    cn->s.clock = sfClock_create();
    sfClock_restart(cn->s.clock);
}

void unload_sprites(cn_t *cn)
{
    for (size_t i = 0; i < S_MAX; i++)
        if (cn->s.sprite[i] != NULL)
            destroy_sprite(cn->s.sprite[i]);
    sfClock_destroy(cn->s.clock);
}

static void update_sprite(cn_t *cn, sprite_t *sprite)
{
    sfIntRect rectangle = {0, 0, 0, 0};
    uint32_t frame;
    uint32_t framew;

    frame = fmodf(cn->s.time, sprite->framelen * (float)sprite->framecount) /
    sprite->framelen;
    if (frame == sprite->frame)
        return;
    sprite->frame = frame;
    framew = sprite->w / sprite->framecount;
    rectangle.left = frame * framew;
    rectangle.width = framew;
    rectangle.height = sprite->h;
    sfSprite_setTextureRect(sprite->sprite, rectangle);
}

void update_sprites_frame(cn_t *cn)
{
    cn->s.time = sfTime_asSeconds(sfClock_getElapsedTime(cn->s.clock));
    for (size_t i = 0; i < S_MAX; i++)
        if (cn->s.sprite[i]->framecount > 1)
            update_sprite(cn, cn->s.sprite[i]);
}
