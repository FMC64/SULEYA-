/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** input headers
*/

#ifndef _INPUT_H
#define _INPUT_H

#define CAM_MOVE 0.06f

#define AIRSTRAFE 50.0f

void init_input(cn_t *cn);
void get_raw_input(cn_t *cn);
void process_input(cn_t *cn);

#endif

