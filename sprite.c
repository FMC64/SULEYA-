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
    sfImage *img;

    res->texture = sfTexture_createFromFile(path, NULL);
    if (res->texture == NULL)
        exit_full_custom();
    vec2 = sfTexture_getSize(res->texture);
    res->w = vec2.x;
    res->h = vec2.y;
    res->data = (uint32_t*)malloc_safe(sizeof(uint32_t) * res->w * res->h);
    img = sfTexture_copyToImage(res->texture);
    memcpy_custom((void*)sfImage_getPixelsPtr(img), res->data,
    4 * res->w * res->h);
    sfImage_destroy(img);
    res->sprite = sfSprite_create();
    sfSprite_setTexture(res->sprite, res->texture, sfTrue);
    return (res);
}

void destroy_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite->data);
    free(sprite);
}
