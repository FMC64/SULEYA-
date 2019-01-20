/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

int poll_events(cn_t *cn)
{
    sfEvent event;

    if (!sfRenderWindow_isOpen(cn->win.window))
        return (0);
    while (sfRenderWindow_pollEvent(cn->win.window, &event))
        switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(cn->win.window);
            return (0);
        default:
            break;
        }
    return (1);
}

void cam_ac(cn_t *cn)
{
    float speed = dist3(cn->player.fun->speed);
    float speedprev = dist3(cn->player.speedprev);

    if ((speed >= speedprev) && (speed > 0.1f))
        cn->cam.shift.x += cn->win.framelen * 2.0f;
    else
        cn->cam.shift.x -= cn->win.framelen * 5.0f;
    if (cn->cam.shift.x > 6.0f)
        cn->cam.shift.x = 6.0f;
    if (cn->cam.shift.x < 0.0f)
        cn->cam.shift.x = 0.0f;
    cn->cam.pos = cn->player.fun->pos;
    cn->cam.pos.z -= 8.0f + cn->cam.shift.x;
    cn->cam.pos.x += cn->player.fun->size.x / 2.0f;
}

static void game_stuff(cn_t *cn)
{
    get_raw_input(cn);
    if (!cn->misc.is_gameover) {
        process_input(cn);
        physx(cn);
        update_player(cn);
        update_ennemy(cn);
        cam_ac(cn);
        cn->player.speedprev = cn->player.fun->speed;
        update_sprites_frame(cn);
        update_objs(cn);
    } else
        gameover_update(cn);
    dj(cn);
    render(cn);
}

void game(cn_t *cn)
{
    reset(cn);
    while (poll_events(cn)) {
        game_stuff(cn);
        if (!cn->gen.do_gen)
            continue;
        if (cn->gen.obj->pos.x - cn->player.fun->pos.x < 100.0f) {
            cn->gen.obj = gen_ter(cn, cn->gen.obj->pos,
            cn->gen.obj->size, cn->sprite[S_PEBBLES_MOD]);
            gen_pub(cn, cn->sprite[S_BENDY], cn->sprite[S_TREE],
            cn->gen.obj->pos);
        }
        if (cn->gen.lastsky->pos.x - cn->player.fun->pos.x <
            1000.0f) {
            cn->gen.lastsky = gen_sky(cn, cn->gen.lastsky, cn->sprite[S_SKY]);
        }
    }
}
