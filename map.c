/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** map lol
*/

#include "headers.h"

static const char* map_handle(const char *new_value, int do_get)
{
    static const char *value = NULL;

    if (do_get)
        return (value);
    else
        value = new_value;
    return (NULL);
}

const char* get_map(void)
{
    return (map_handle(0, 1));
}

void set_map(const char *path)
{
    map_handle(path, 0);
}

static void remove_linefeeds(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}

void load_map(cn_t *cn)
{
    char *str;
    size_t n = 0;
    FILE *file = fopen(get_map(), "rb");

    if (file == NULL) {
        my_putstr_fd(2, "Can't open such map.\n");
        exit_full_custom();
    }
    cn->misc.end = 0.0f;
    while (getline(&str, &n, file) >= 0) {
        remove_linefeeds(str);
        map_parse(cn, str);
    }
    fclose(file);
}
