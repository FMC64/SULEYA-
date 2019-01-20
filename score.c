/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** score lol
*/

#include "headers.h"

uint64_t get_highscore(void)
{
    uint64_t res = 0;
    size_t got;
    FILE *file;

    file = fopen("score.bin", "rb");
    if (file == NULL)
        return (res);
    got = fread(&res, sizeof(uint64_t), 1, file);
    if (got != 1) {
        fclose(file);
        return (0);
    }
    return (res);
}

void set_highscore(uint64_t score)
{
    FILE *file;

    file = fopen("score.bin", "wb+");
    if (file == NULL)
        return;
    fwrite(&score, sizeof(uint64_t), 1, file);
    fclose(file);
}
