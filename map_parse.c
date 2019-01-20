/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** map lol
*/

#include "headers.h"

static void write_token(int fd, char token)
{
    if (token == '\0')
        my_putstr_fd(fd, "\\0");
    else if (token == '\n')
        my_putstr_fd(fd, "\\n");
    else
        write(fd, &token, 1);
}

static void expect_token(const char *src, size_t *i, char token)
{
    for (; src[*i] == ' '; (*i)++);
    if (src[*i] != token) {
        my_putstr_fd(2, "Error: expected '");
        write_token(2, token);
        my_putstr_fd(2, "' but got '");
        write_token(2, src[*i]);
        my_putstr_fd(2, "'.\n");
        exit_full_custom();
    }
    (*i)++;
    for (; src[*i] == ' '; (*i)++);
}

vec3 read_vec3(const char *src, size_t *i)
{
    vec3 res;

    for (; src[*i] == ' '; (*i)++);
    res.x = get_float(src, i);
    expect_token(src, i, ',');
    res.y = get_float(src, i);
    expect_token(src, i, ',');
    res.z = get_float(src, i);
    return (res);
}

vec2 read_vec2(const char *src, size_t *i)
{
    vec2 res;

    for (; src[*i] == ' '; (*i)++);
    res.x = get_float(src, i);
    expect_token(src, i, ',');
    res.y = get_float(src, i);
    return (res);
}

void map_parse(cn_t *cn, const char *src)
{
    vec3 pos;
    vec2 size;
    uint64_t sprite;
    uint64_t is_destroyable;
    size_t i = 0;
    obj_fun_t *fun;

    pos = read_vec3(src, &i);
    expect_token(src, &i, ';');
    size = read_vec2(src, &i);
    expect_token(src, &i, ';');
    sprite = get_int(src, &i);
    expect_token(src, &i, ';');
    is_destroyable = get_int(src, &i);
    expect_token(src, &i, '\0');
    fun = add_obj_fun(cn, pos, size, cn->sprite[sprite]);
    fun->is_destroyable = is_destroyable;
    if (pos.x > cn->misc.end)
        cn->misc.end = pos.x;
}
