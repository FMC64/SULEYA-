/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

int main(int argc, char **argv, char **env)
{
    cn_t *cn;

    (void)argc;
    (void)argv;
    if (env[0] == NULL)
        return (84);
    cn = init();
    if (cn == NULL)
        return (84);
    game(cn);
    quit(cn);
    return (EXIT_SUCCESS);
}
