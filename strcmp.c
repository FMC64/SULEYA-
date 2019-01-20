/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** str fun
*/

#include "headers.h"

int my_strcmp(const char *a, const char *b)
{
    for (size_t i = 0;; i++) {
        if (a[i] != b[i])
            return ((int)a[i] - (int)b[i]);
        if (a[i] == '\0')
            break;
    }
    return (0);
}
