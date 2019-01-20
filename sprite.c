/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** sprite things
*/

#include "headers.h"

sprite_t* dup_sprite(sprite_t *src)
{
    sprite_t *res = (sprite_t*)malloc_safe(sizeof(sprite_t));

    *res = *src;
    res->sprite = sfSprite_create();
    res->framecount = 1;
    if (res->sprite == NULL)
        exit_full_custom();
    sfSprite_setTexture(res->sprite, src->texture, sfTrue);
    return (res);
}

static void sprite_set_default_values(sprite_t *sprite)
{
    sfTexture_setRepeated(sprite->texture, sfTrue);
    sprite->frame = -1;
    sprite->framecount = 1;
    sprite->framelen = 1.0f;
    sprite->clock = NULL;
    sprite->scalex = 0.0f;
    sprite->scaley = 0.0f;
}

sprite_t* create_sprite(const char *path)
{
    sprite_t *res = (sprite_t*)malloc_safe(sizeof(sprite_t));
    sfVector2u vec2;

    res->texture = sfTexture_createFromFile(path, NULL);
    if (res->texture == NULL)
        exit_full_custom();
    vec2 = sfTexture_getSize(res->texture);
    res->truew = vec2.x;
    res->w = vec2.x;
    res->h = vec2.y;
    sprite_set_default_values(res);
    res->sprite = sfSprite_create();
    if (res->sprite == NULL)
        exit_full_custom();
    sfSprite_setTexture(res->sprite, res->texture, sfTrue);
    return (res);
}

void destroy_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    if (sprite->clock != NULL)
        sfClock_destroy(sprite->clock);
    free(sprite);
}
