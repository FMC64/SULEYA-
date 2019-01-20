/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** str fun
*/

#ifndef _STR_H
#define _STR_H

size_t my_strlen(const char *str);
void my_putchar_fd(int fd, char to_print);
void my_putchar(char to_print);
void my_putstr(const char *str);
void my_putstr_fd(int fd, const char *str);

int my_strcmp(const char *a, const char *b);

void usage(void);

float get_float(const char *input, size_t *i);
uint64_t get_int(const char *input, size_t *i);

#endif
