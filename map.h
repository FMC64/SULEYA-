/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** map lol
*/

#ifndef _MAP_H
#define _MAP_H

const char* get_map(void);
void set_map(const char *path);
void load_map(cn_t *cn);

void map_parse(cn_t *cn, const char *src);

#endif
