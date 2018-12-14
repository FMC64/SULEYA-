/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

sfRenderStates get_default_render_states(void)
{
    sfRenderStates res;

    res.blendMode = sfBlendAlpha;
    res.transform = sfTransform_Identity;
    res.texture = NULL;
    res.shader = NULL;
    return (res);
}

void render_tilemap(obj_tilemap_t *tilemap)
{

}

void render(cn_t *cn)
{
    for (size_t i = 0; i < cn->objs.count; i++) {
        switch (cn->objs.obj[i].type) {
            case OBJ_TILEMAP:
            render_tilemap(cn->objs.obj[i].data);
            break;
            default:
            break;
        }
    }
}
