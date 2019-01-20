/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** some structs
*/

#ifndef _SOUND_STRUCT_H
#define _SOUND_STRUCT_H

typedef enum {
    SD_FLAME,
    SD_PLANK_BREAK_1,
    SD_PLANK_BREAK_2,
    SD_PLANK_BREAK_3,
    SD_MAX
} sound_data_t;

typedef struct {
    sfSound *sound;
    sfSoundBuffer *buf;
} sound_t;

typedef struct {
    sound_data_t index;
    const char *path;
} sound_data_descriptor_t;

typedef struct {
    sound_data_t index;
    const char *path;
    float attenuation;
} sound_data_relative_descriptor_t;

#endif
