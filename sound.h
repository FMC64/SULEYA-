/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** sound things
*/

#ifndef _SOUND_H
#define _SOUND_H

void load_sounds(cn_t *cn);
void unload_sounds(cn_t *cn);
void stop_sounds(cn_t *cn);

void stop_music(cn_t *cn);
void play_music(cn_t *cn, const char *path, int do_loop);
void dj(cn_t *cn);

#endif
