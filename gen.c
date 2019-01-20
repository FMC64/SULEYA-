/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** generation !
*/

#include "headers.h"

void gen_next(cn_t *cn)
{
    switch (cn->gen.biome) {
    case BIOME_DEPOT:
        gen_depot(cn);
        break;
    default:
        break;
    }
    if (cn->gen.y > cn->misc.death_barrier - 10.0f)
        cn->gen.y = cn->misc.death_barrier - 10.0f;
    if (cn->gen.y < -30.0f)
        cn->gen.y = -30.0f;
}
