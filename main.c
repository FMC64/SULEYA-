/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

int get_args(int argc, char **argv)
{
    if ((argc == 2) && (my_strcmp(argv[1], "-h") == 0)) {
        usage();
        return (0);
    }
    if (argc > 2) {
        my_putstr_fd(2, "Woah ! Too many maps\n");
        exit_full_custom();
    }
    if (argc == 2)
        set_map(argv[1]);
    return (1);
}

static int intro_menu(cn_t *cn)
{
    if (!intro(cn)) {
        quit(cn);
        return (0);
    }
    if (!menu(cn)) {
        quit(cn);
        return (0);
    }
    return (1);
}

int main(int argc, char **argv, char **env)
{
    cn_t *cn;

    if (env[0] == NULL)
        return (84);
    if (!get_args(argc, argv))
        return (0);
    cn = init();
    if (cn == NULL)
        return (84);
    //if (!intro_menu(cn))
    //    return (0);
    game(cn);
    quit(cn);
    return (EXIT_SUCCESS);
}
