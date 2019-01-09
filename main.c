/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

static int poll_events(cn_t *cn)
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

void add_map(cn_t *cn, spritesheet_t *sheet)
{
    obj_t *obj;
    uint32_t *layer;

    obj = add_obj_tilemap(cn, (vec3){0.0f, 0.0f, -2.0f}, 32, 32);
    obj_tilemap_set_sheet(obj, sheet);
    layer = obj_tilemap_add_layer(obj);
    for (int i = 0; i < 32 * 32; i++)
        layer[i] = i;
}

void cam_ac(cn_t *cn)
{
    float lim = 4.0f;

    cn->cam.pos = cn->player.pos;
    cn->cam.pos.z -= 12.0f;
    cn->cam.shift.x += cn->player.speed.x * cn->win.framelen * 0.6f;
    if (cn->cam.shift.x < -lim) {
        cn->cam.shift.x = -lim;
    }
    if (cn->cam.shift.x > lim) {
        cn->cam.shift.x = lim;
    }
    cn->cam.pos.x += cn->player.size.x / 2.0f;
}

int main(int argc, char **argv, char **env)
{
    cn_t *cn;
    sprite_t *sprite;
    spritesheet_t *sheet;

    (void)argc;
    (void)argv;
    if (env[0] == NULL)
        return (84);
    cn = init();
    if (cn == NULL)
        return (84);
    sprite = create_sprite("res/pebbles.jpg");
    sheet = create_spritesheet("res/sheet.png", 32);
    cn->player.sprite = create_sprite("res/basho.jpg");
    cn->player.pos = (vec3){0.0f, -3.0f, 0.0f};
    cn->player.speed = (vec3){0.0f, 0.0f, 0.0f};
    cn->player.size = (vec2){1.0f, 2.0f};
    cn->player.is_grounded = 0;
    //add_map(cn, sheet);
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            for (int k = 0; k < 3; k++)
                add_obj_fun(cn, (vec3){i * 4, j * 4, k * 10}, (vec2){1.0f, 1.0f}, sprite);
    add_obj_fun(cn, (vec3){-20.0f, 0.0f, 0.0f}, (vec2){10.0f, 5.0f}, sprite);
    add_obj_fun(cn, (vec3){-60.0f, 0.0f, 0.0f}, (vec2){30.0f, 50.0f}, sprite);
    while (poll_events(cn)) {
        poll_input(cn);
        physx(cn);
        cam_ac(cn);
        sfRenderWindow_clear(cn->win.window, sfBlack);
        render(cn);
        render_present(cn);
    }
    destroy_sprite(sprite);
    destroy_spritesheet(sheet);
    quit(cn);
    return (EXIT_SUCCESS);
}
