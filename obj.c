/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj insertion
*/

#include "headers.h"

static obj_t* add_obj(objset_t *set)
{
    uint64_t cur = set->count++;
    obj_t *new_obj;

    if (set->count > set->allocated) {
        set->allocated += OBJ_ALLOC_STEP;
        new_obj = (obj_t*)malloc_safe(sizeof(obj_t) * set->allocated);
        for (uint64_t i = 0; i < cur; i++)
            new_obj[i] = set->obj[i];
        free(set->obj);
        set->obj = new_obj;
    }
    return (&set->obj[cur]);
}

static obj_t* add_set(cn_t *cn, float z)
{
    uint64_t cur = cn->objs.count++;
    uint64_t to_ins;
    objset_t *new_set;

    if (cn->objs.count > cn->objs.allocated) {
        cn->objs.allocated += OBJ_ALLOC_STEP;
        new_set =
        (objset_t*)malloc_safe(sizeof(objset_t) * cn->objs.allocated);
        for (uint64_t i = 0; i < cur; i++)
            new_set[i] = cn->objs.set[i];
        free(cn->objs.set);
        cn->objs.set = new_set;
    }
    for (to_ins = 0; (to_ins < cur) && (cn->objs.set[to_ins].z > z); to_ins++);
    for (uint64_t i = cur; i > to_ins; i--)
        cn->objs.set[i] = cn->objs.set[i - 1];
    cn->objs.set[to_ins] = (objset_t){z, 1, OBJ_ALLOC_STEP,
    malloc_safe(sizeof(obj_t) * OBJ_ALLOC_STEP)};
    return (&cn->objs.set[to_ins].obj[0]);
}

obj_t* get_obj_slot(cn_t *cn, float z)
{
    for (uint64_t i = 0; i < cn->objs.count; i++)
        if (cn->objs.set[i].z == z)
            return (add_obj(&cn->objs.set[i]));
    return (add_set(cn, z));
}

void free_obj(obj_t *obj)
{
    switch (obj->type) {
        case OBJ_FUN:
        free_obj_fun(obj->data);
        break;
        case OBJ_TILEMAP:
        free_obj_tilemap(obj->data);
        break;
        default:
        break;
    }
}

void free_objs(cn_t *cn)
{
    for (size_t i = 0; i < cn->objs.count; i++) {
        for (size_t j = 0; j < cn->objs.set[i].count; j++)
            free_obj(&cn->objs.set[i].obj[j]);
        free(cn->objs.set[i].obj);
    }
    free(cn->objs.set);
}
