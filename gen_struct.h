/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _GEN_STRUCT_H
#define _GEN_STRUCT_H

typedef enum {
    BIOME_DEPOT
} gen_biome_t;

typedef struct {
    int is_bridge;
    float light;
} gen_depot_t;

typedef struct {
    int do_gen;
    gen_depot_t depot;
    gen_biome_t biome;
    float x;
    float y;
    float bg;
} gen_t;

#endif
