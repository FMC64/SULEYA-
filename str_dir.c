/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__ls
** File description:
** str fun
*/

#include "headers.h"

char* path_append(const char *base, const char *next)
{
    size_t lenbase = my_strlen(base);
    size_t lennext = my_strlen(next);
    size_t i;
    char *res;

    res = malloc_safe(lenbase + lennext + 2);
    for (i = 0; i < lenbase; i++)
        res[i] = base[i];
    if ((lenbase == 0) || (base[lenbase - 1] != '/'))
        res[i++] = '/';
    for (size_t j = 0; j < lennext; j++)
        res[i + j] = next[j];
    res[i + lennext] = '\0';
    return (res);
}
