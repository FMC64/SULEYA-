/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** ennemy behaviour
*/

#include "headers.h"

void update_ennemy(cn_t *cn)
{
    vec3 rel = {cn->flame.pos.x - cn->cam.pos.x, 0.0f,
    cn->flame.pos.z - cn->cam.pos.z};

    cn->flame.speed.x += 0.1f * cn->win.framelen;
    cn->flame.pos.x += cn->flame.speed.x * cn->win.framelen;
    cn->flame.flame_obj->pos.x = cn->flame.pos.x - 50.0f;
    for (size_t i = 0; i < FLAME_COUNT; i++)
        cn->flame.obj[i]->pos.x = cn->flame.pos.x;
    sfSound_setPosition(cn->sound[SD_FLAME].sound,
    (sfVector3f){1000.0, 1000.0f,
    1000.0f});
    sfSound_setVolume(cn->sound[SD_FLAME].sound, (100.0f /
    (rel.x * rel.x + rel.z * rel.z)) * 100.0f);
}
