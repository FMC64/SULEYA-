/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** obj DESUTOREKUSHON
*/

#include "headers.h"

static void gen_two_rects(uint64_t count,
split_rects_t *rects, rect_t cur, float ratio)
{
    if (rand() % 2) {
        rects->rect[rects->count] =
        (rect_t){cur.x, cur.y, cur.w * ratio, cur.h};
        gen_split_rec(count, rects, rects->count++);
        rects->rect[rects->count] =
        (rect_t){cur.x + cur.w * ratio, cur.y, cur.w * (1.0f - ratio), cur.h};
        gen_split_rec(count, rects, rects->count++);
    } else {
        rects->rect[rects->count] =
        (rect_t){cur.x, cur.y, cur.w, cur.h * ratio};
        gen_split_rec(count, rects, rects->count++);
        rects->rect[rects->count] =
        (rect_t){cur.x, cur.y + cur.h * ratio, cur.w, cur.h * (1.0f - ratio)};
        gen_split_rec(count, rects, rects->count++);
    }
}

void gen_split_rec(uint64_t count, split_rects_t *rects,
uint64_t to_split)
{
    rect_t cur = rects->rect[to_split];

    if (count == 0)
        return;
    gen_two_rects(count - 1, rects, cur,
    (randf() / 2.0f) + 0.25f);
    rects->rect[to_split] = rects->rect[rects->count - 1];
    rects->count--;
}

static split_rects_t gen_split(uint64_t count)
{
    split_rects_t res = {1, {{0.0f, 0.0f, 1.0f, 1.0f}}};

    gen_split_rec(count, &res, 0);
    return (res);
}

void add_split_obj(cn_t *cn, obj_fun_t *fun, rect_t rect, vec2 impulse)
{
    obj_fun_t *add;

    add = add_obj_fun(cn, (vec3){fun->pos.x +
    fun->size.x * rect.x, fun->pos.y + fun->size.y * rect.y, fun->pos.z},
    (vec2){fun->size.x * rect.w, fun->size.y * rect.h}, fun->sprite);
    add->sprite = dup_sprite(fun->sprite);
    sfSprite_setTextureRect(add->sprite->sprite,
    (sfIntRect){(float)fun->sprite->w * rect.x, (float)fun->sprite->h * rect.y,
    (float)fun->sprite->w * rect.w, (float)fun->sprite->h * rect.h});
    add->sprite->w = (float)fun->sprite->w * rect.w;
    add->sprite->h = (float)fun->sprite->h * rect.h;
    add->is_static = 0;
    add->is_collider = 0;
    add->is_sprite_linked = 1;
    add->speed.x = impulse.x * 15.0f * (0.8f + randf() * 0.4f);
    add->speed.y = (randf() * 2.0f - 1.0f) * 5.0f;
    obj_fun_set_life(add, 15.0f);
}

void split_obj(cn_t *cn, objset_t *set, uint64_t i, vec2 impulse)
{
    obj_fun_t *fun = set->obj[i].data;
    split_rects_t split;

    split = gen_split(5);
    for (size_t i = 0; i < split.count; i++)
        add_split_obj(cn, fun, split.rect[i], impulse);
    destroy_obj(set, i);
}
