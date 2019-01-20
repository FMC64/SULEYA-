/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** rip :(
*/

#include "headers.h"

void gameover(cn_t *cn, int has_won)
{
    stop_sounds(cn);
    play_music(cn, has_won ? "res/snd/sfx/sonic-woah.ogg" :
    "res/snd/sfx/jojo-oh-no.ogg", 0);
    cn->playlist.is_active = 0;
    if (cn->misc.score > cn->misc.highscore) {
        cn->misc.highscore = cn->misc.score;
        set_highscore(cn->misc.score);
    }
    cn->misc.is_gameover = 1;
    cn->misc.has_won = has_won;
}

void gameover_update(cn_t *cn)
{
    if (sfMusic_getStatus(cn->playlist.current) != sfPlaying)
        play_music(cn,
        "res/snd/music/SID-Sound, 시간의 흉터.ogg", 1);
    if (sfKeyboard_isKeyPressed(sfKeyA))
        reset(cn);
}
