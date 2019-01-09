/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** macro fun
*/

#ifndef _MACRO_H
#define _MACRO_H

#ifndef MIN
#define MIN(a, b) (a < b ? a : b)
#endif

#ifndef MAX
#define MAX(a, b) (a > b ? a : b)
#endif

#ifndef ABS
#define ABS(value) ((value) < 0 ? (-value) : (value))
#endif

#define RENDER_TILEMAP_RECT (&(sfIntRect){tile % tilemap->sheet->w * \
tilemap->sheet->size, tile / tilemap->sheet->w * tilemap->sheet->size, \
tilemap->sheet->size, tilemap->sheet->size})

#endif
