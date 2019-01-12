/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

void add_phys_col(vec2 to_add, vec2 *acc)
{
    acc->x += to_add.x * 1.01f;
    acc->y += to_add.y * 1.01f;
}

static void test_col_set(cn_t *cn, objset_t set, vec2 *vec)
{
    for (size_t i = 0; i < set.count; i++) {
        switch (set.obj[i].type) {
        case OBJ_FUN:
            phys_fun(cn, set.obj[i].data, vec);
            break;
        default:
            break;
        }
    }
}

static void manage_is_grounded(cn_t *cn)
{
    if (cn->player.is_grounded) {
        if (cn->player.speed.x > 0.0f) {
            cn->player.speed.x -= 50.0f * cn->win.framelen;
            if (cn->player.speed.x < cn->player.maxsx) {
                cn->player.maxsx = cn->player.speed.x;
                if (cn->player.maxsx < 14.0f)
                    cn->player.maxsx = 14.0f;
            }
            if (cn->player.speed.x < 0.0f)
                cn->player.speed.x = 0.0f;
        } else if (cn->player.speed.x < 0.0f) {
            cn->player.speed.x += 50.0f * cn->win.framelen;
            if (cn->player.speed.x > -cn->player.maxsx) {
                cn->player.maxsx = cn->player.speed.x;
                if (cn->player.maxsx < 14.0f)
                    cn->player.maxsx = 14.0f;
            }
            if (cn->player.speed.x > 0.0f)
                cn->player.speed.x = 0.0f;
        }
        cn->player.is_grounded = 0;
    }
}

void physx(cn_t *cn)
{
    vec2 vec;
    vec2 vec_start;

    manage_is_grounded(cn);
    cn->player.speed.y += 30.0f * cn->win.framelen;
    vec = (vec2){cn->player.speed.x * cn->win.framelen,
    cn->player.speed.y * cn->win.framelen};
    vec_start = vec;
    for (size_t i = 0; i < cn->objs.count; i++) {
        if (cn->objs.set[i].z == cn->player.pos.z)
            test_col_set(cn, cn->objs.set[i], &vec);
    }
    if (vec.y - vec_start.y < 0.0f)
        cn->player.is_grounded = 1;
    cn->player.speed.x = vec.x / cn->win.framelen;
    cn->player.speed.y = vec.y / cn->win.framelen;
    cn->player.pos.x += cn->player.speed.x * cn->win.framelen;
    cn->player.pos.y += cn->player.speed.y * cn->win.framelen;
}
