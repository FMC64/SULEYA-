/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** sprite things
*/

#include "headers.h"

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
    res->sprite = sfSprite_create();
    res->frame = -1;
    res->framecount = 1;
    res->framelen = 1.0f;
    res->clock = NULL;
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
