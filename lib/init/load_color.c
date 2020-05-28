/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** load_color
*/

#include "../../include/my_world.h"

void check_color_save(t_elem *e, int i, int highest)
{
    if (highest > 0 && highest <= 200)
        e->save[i] = sfGreen;
    else if (highest > 200)
        e->save[i] = sfYellow;
    else
        e->save[i] = sfBlue;
}

void load_color_save(t_elem *e)
{
    int high = 0;
    int i = 0;

    e->save = malloc(sizeof(*e->save) * pow(e->width - 1, 2));
    for (int y = 0; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            if (x + 1 < e->width && y + 1 < e->height) {
                high = highest(e->map[y][x], e->map[y + 1][x], \
                e->map[y + 1][x + 1], e->map[y][x + 1]);
                check_color_save(e, i, high);
                i += 1;
            }
        }
    }
}