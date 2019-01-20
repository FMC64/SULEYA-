/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj insertion
*/

#include "headers.h"

static void update_obj_fun(cn_t *cn, obj_fun_t *fun, objset_t *set, uint64_t i)
{
    if (((fun->pos.x + fun->size.x) < (cn->flame.pos.x - 200.0f)) ||
    (fun->pos.y > 1000.0f)) {
        if (fun == cn->flame.flame_obj)
            return;
        destroy_obj(set, i);
        return;
    }
    if (fun->life == 0.0f)
        return;
    if (dist3_sq(vec3_sub(fun->pos, cn->player.fun->pos)) > 400.0f) {
        destroy_obj(set, i);
        return;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(fun->clock)) > fun->life)
        destroy_obj(set, i);
}

static void update_obj(cn_t *cn, objset_t *set, uint64_t i)
{
    switch (set->obj[i].type) {
    case OBJ_FUN:
        update_obj_fun(cn, set->obj[i].data, set, i);
        break;
    default:
        break;
    }
}

void update_objs(cn_t *cn)
{
    for (size_t i = 0; i < cn->objs.count; i++)
        for (size_t j = 0; j < cn->objs.set[i].count; j++)
            update_obj(cn, &cn->objs.set[i], j);
}
