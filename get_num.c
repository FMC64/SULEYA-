/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** num get
*/

#include "headers.h"

static int is_digit(char src)
{
    return ((src >= '0') && (src <= '9'));
}

static float get_pow(size_t size)
{
    float res = 1.0;

    if (size == 0) {
        my_putstr_fd(2, "Error: No integer part.\n");
        exit_full_custom();
    }
    for (size_t i = 0; i < (size - 1); i++)
        res *= 10;
    return (res);
}

static float read_decimals(const char *input, size_t *i)
{
    float pow = 1.0f;
    float res = 0.0f;

    if (input[*i] != '.')
        return (0.0f);
    (*i)++;
    while (is_digit(input[*i])) {
        pow /= 10.0f;
        res += (input[*i] - '0') * pow;
        (*i)++;
    }
    return (res);
}

float get_float(const char *input, size_t *i)
{
    size_t size;
    float res = 0.0f;
    float pow;
    float sign = 1.0;

    if (input[*i] == '-') {
        sign = -1.0f;
        (*i)++;
    }
    for (size = 0; is_digit(input[*i + size]); size++);
    pow = get_pow(size);
    for (size_t j = 0; j < size; j++) {
        res += (input[*i + j] - '0') * pow;
        pow /= 10.0f;
    }
    (*i) += size;
    return ((res + read_decimals(input, i)) * sign);
}

uint64_t get_int(const char *input, size_t *i)
{
    size_t size;
    uint64_t res = 0.0f;
    uint64_t pow = 1;

    for (size = 0; is_digit(input[*i + size]); size++);
    if (size == 0) {
        my_putstr_fd(2, "Error: No integer part.\n");
        exit_full_custom();
    }
    for (size_t j = 0; j < (size - 1); j++)
        pow *= 10;
    for (size_t j = 0; j < size; j++) {
        res += (input[*i + j] - '0') * pow;
        pow /= 10;
    }
    (*i) += size;
    return (res);
}
