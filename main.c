/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** main
*/

#include "headers.h"

int main(int argc, char **argv)
{
    cn_t *cn;

    (void)argc;
    (void)argv;
    cn = init();
    if (cn == NULL)
        return (84);
    return (EXIT_SUCCESS);
}
