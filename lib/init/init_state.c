/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_state
*/

#include "../../include/my_world.h"

void init_state_quad(t_elem *e)
{
    e->quad = malloc(sizeof(*e->quad) * pow(e->width - 1, 2));
    for (int i = 0; i < pow(e->width - 1, 2); i += 1)
        e->quad[i].state = NONE;
}

void init_state_button(t_elem *e)
{
    for (int i = 0; i < NBBUTTON; i += 1)
        add_state_element(&e->button, NONE);
}

int is_inmap(t_elem *e, sfMouseMoveEvent b)
{
    sfVector2f max = {0, 0};
    for (int y = 0; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            if (x == 0 && y == 0)
                max = (sfVector2f){e->map2[x][y].x, e->map2[x][y].y};
            if (max.x < e->map2[x][y].x)
                max.x = e->map2[x][y].x;
            if (max.y < e->map2[x][y].y)
                max.y = e->map2[x][y].y;
        }
    }
    if ((b.x > max.x) || (b.y > max.y))
        return (1);
    return (0);
}

int is_inmap_button(t_elem *e, sfMouseButtonEvent b)
{
    sfVector2f max = {0, 0};
    for (int y = 0; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            if (x == 0 && y == 0)
                max = (sfVector2f){e->map2[x][y].x, e->map2[x][y].y};
            if (max.x < e->map2[x][y].x)
                max.x = e->map2[x][y].x;
            if (max.y < e->map2[x][y].y)
                max.y = e->map2[x][y].y;
        }
    }
    if ((b.x > max.x) || (b.y > max.y))
        return (1);
    return (0);
}