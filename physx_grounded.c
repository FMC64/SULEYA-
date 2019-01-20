/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static void phys_is_grounded_pos_sp(cn_t *cn, obj_fun_t *fun)
{
    fun->speed.x -= fun->friction * cn->win.framelen;
    if (fun->speed.x < 0.0f)
        fun->speed.x = 0.0f;
}

static void phys_is_grounded_neg_sp(cn_t *cn, obj_fun_t *fun)
{
    fun->speed.x += fun->friction * cn->win.framelen;
    if (fun->speed.x > 0.0f)
        fun->speed.x = 0.0f;
}

void phys_is_grounded(cn_t *cn, obj_fun_t *fun)
{
    if (fun->is_grounded) {
        if (fun->speed.x > 0.0f)
            phys_is_grounded_pos_sp(cn, fun);
        else if (fun->speed.x < 0.0f)
            phys_is_grounded_neg_sp(cn, fun);
        fun->is_grounded = 0;
        fun->last_grounded = 0;
    } else
        fun->last_grounded++;
}
