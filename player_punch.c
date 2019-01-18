/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** ce qu'il se passe lorsque basho est AGACÉ
*/

#include "headers.h"

static void punch_obj(cn_t *cn, objset_t *set, uint64_t i, rect_t trigger)
{
    obj_fun_t *fun;

    switch (set->obj[i].type) {
    case OBJ_FUN:
        fun = set->obj[i].data;
        if ((fun == cn->player.fun) || (!fun->is_destroyable))
            return;
        if (rect_inter(trigger, (rect_t){fun->pos.x, fun->pos.y,
        fun->size.x, fun->size.y}))
            split_obj(cn, set, i,
            cn->player.is_right ? (vec2){1.0f, 0.0f} : (vec2){-1.0f, 0.0f});
        break;
    default:
        break;
    }
}

static void punch_set(cn_t *cn, uint64_t i, rect_t trigger)
{
    for (size_t j = 0; j < cn->objs.set[i].count; j++)
        punch_obj(cn, &cn->objs.set[i], j, trigger);
}

void player_punch(cn_t *cn)
{
    rect_t trigger = {cn->player.fun->pos.x, cn->player.fun->pos.y + 0.7f,
    cn->player.fun->size.x / 2.0f, cn->player.fun->size.y / 1.4f};

    if (cn->player.is_right)
        trigger.x += cn->player.fun->size.x / 2.0f;
    for (size_t i = 0; i < cn->objs.count; i++)
        if (cn->objs.set[i].z == cn->player.fun->pos.z)
            punch_set(cn, i, trigger);
}
