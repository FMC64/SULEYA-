/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** sound things
*/

#include "headers.h"

static const char *playlist[] = {
    "res/snd/music/キミノヨゾラ哨戒班 ⁄ Orangestar feat.IA.ogg",
    "res/snd/music/イデア ／ 天月-あまつき"
    "-【オリジナル】.ogg",
    "res/snd/music/Demetori - 信仰は儚き人間の為に"
    " ～ Jehovah's YaHVeH.ogg",
    NULL
};

static uint64_t get_playlist_size(void)
{
    uint64_t res;

    for (res = 0; playlist[res] != NULL; res++);
    return (res);
}

void stop_music(cn_t *cn)
{
    if (cn->playlist.current != NULL) {
        sfMusic_stop(cn->playlist.current);
        sfMusic_destroy(cn->playlist.current);
        cn->playlist.current = NULL;
        cn->playlist.index = ~0ULL;
    }
}

void play_music(cn_t *cn, const char *path, int do_loop)
{
    stop_music(cn);
    cn->playlist.current = sfMusic_createFromFile(path);
    if (cn->playlist.current == NULL)
        exit_full_custom();
    sfMusic_setLoop(cn->playlist.current, do_loop);
    sfMusic_play(cn->playlist.current);
}

void dj(cn_t *cn)
{
    uint64_t count;

    if (!cn->playlist.is_active)
        return;
    count = get_playlist_size();
    if (cn->playlist.current == NULL) {
        play_music(cn, playlist[rand() % count], 0);
        return;
    } else if (sfMusic_getStatus(cn->playlist.current) == sfPlaying)
        return;
    cn->playlist.index = (cn->playlist.index + 1) % count;
    play_music(cn, playlist[cn->playlist.index], 0);
}

void init_playlist(cn_t *cn)
{
    cn->playlist.index = ~0ULL;
    cn->playlist.current = NULL;
    cn->playlist.is_active = 0;
}
