/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

sfrenderstate_t get_default_render_states(void)
{
    sfRenderStates res;

    res.blendMode = sfBlendAlpha;
    res.transform = sfTransform_Identity;
    res.texture = NULL;
    res.shader = NULL;
    return (res);
}

static void render_obj(cn_t *cn, obj_t *obj)
{
    switch (obj->type) {
        case OBJ_FUN:
        render_fun(cn, obj->data);
        break;
        case OBJ_TILEMAP:
        render_tilemap(cn, obj->data);
        break;
        default:
        break;
    }
}

void render(cn_t *cn)
{
    for (size_t i = 0; i < cn->objs.count; i++) {
        for (size_t j = 0; j < cn->objs.set[i].count; j++)
            render_obj(cn, &cn->objs.set[i].obj[j]);
        if (cn->objs.set[i].z == cn->player.pos.z)
            render_player(cn);
    }
}
