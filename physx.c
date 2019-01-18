/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static void test_col_set(obj_fun_t *fun, objset_t set, vec2 *vec)
{
    for (size_t i = 0; i < set.count; i++) {
        if (fun == set.obj[i].data)
            continue;
        switch (set.obj[i].type) {
        case OBJ_FUN:
            phys_fun(fun, set.obj[i].data, vec);
            break;
        default:
            break;
        }
    }
}

static void physx_fun(cn_t *cn, obj_fun_t *fun)
{
    vec2 vec;
    vec2 vec_start;

    if (fun->is_static)
        return;
    phys_is_grounded(cn, fun);
    fun->speed.y += 30.0f * cn->win.framelen;
    vec = (vec2){fun->speed.x * cn->win.framelen,
    fun->speed.y * cn->win.framelen};
    vec_start = vec;
    for (size_t i = 0; i < cn->objs.count; i++) {
        if (cn->objs.set[i].z == fun->pos.z)
            test_col_set(fun, cn->objs.set[i], &vec);
    }
    if (vec.y - vec_start.y < 0.0f)
        fun->is_grounded = 1;
    fun->speed.x = vec.x / cn->win.framelen;
    fun->speed.y = vec.y / cn->win.framelen;
    fun->pos.x += fun->speed.x * cn->win.framelen;
    fun->pos.y += fun->speed.y * cn->win.framelen;
}

static void physx_obj(cn_t *cn, obj_t *obj)
{
    switch (obj->type) {
    case OBJ_FUN:
        physx_fun(cn, obj->data);
        break;
    default:
        break;
    }
}

void physx(cn_t *cn)
{
    for (size_t i = 0; i < cn->objs.count; i++)
        for (size_t j = 0; j < cn->objs.set[i].count; j++)
            physx_obj(cn, &cn->objs.set[i].obj[j]);
}
