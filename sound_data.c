/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** sound things
*/

#include "headers.h"

static const sound_data_descriptor_t sound_data[] = {
    {SD_FLAME, "res/snd/sfx/spacex_test.ogg"},
    {0, NULL}
};

static const sound_data_relative_descriptor_t sound_rel_data[] = {
    {0, NULL, 0.0f}
};

static sound_t create_sound(const char *path)
{
    sound_t res;

    res.sound = sfSound_create();
    if (res.sound == NULL)
        exit_full_custom();
    res.buf = sfSoundBuffer_createFromFile(path);
    if (res.buf == NULL)
        exit_full_custom();
    sfSound_setBuffer(res.sound, res.buf);
    return (res);
}

void load_sounds(cn_t *cn)
{
    for (size_t i = 0; i < SD_MAX; i++) {
        cn->sound[i].sound = NULL;
        cn->sound[i].buf = NULL;
    }
    for (size_t i = 0; sound_data[i].path != NULL; i++)
        cn->sound[sound_data[i].index] = create_sound(sound_data[i].path);
    for (size_t i = 0; sound_rel_data[i].path != NULL; i++) {
        cn->sound[sound_rel_data[i].index] =
        create_sound(sound_rel_data[i].path);
        sfSound_setRelativeToListener(cn->sound[sound_rel_data[i].index].sound,
        sfTrue);
        sfSound_setAttenuation(cn->sound[sound_rel_data[i].index].sound,
        sound_rel_data[i].attenuation);
    }
}

void unload_sounds(cn_t *cn)
{
    for (size_t i = 0; i < SD_MAX; i++) {
        sfSound_stop(cn->sound[i].sound);
        sfSound_destroy(cn->sound[i].sound);
        sfSoundBuffer_destroy(cn->sound[i].buf);
    }
}

void stop_sounds(cn_t *cn)
{
    for (size_t i = 0; i < SD_MAX; i++)
        sfSound_stop(cn->sound[i].sound);
}
