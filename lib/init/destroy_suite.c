/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** destroy_suite
*/

#include "../../include/my_world.h"

void destroy_state(t_elem *e)
{
    free(e->quad);
    for (; e->button; remove_state_element(&e->button, 1));
}

void destroyer_resize(t_elem *e)
{
    destroy_vertex(e);
    destroy_mapvect(e);
    destroy_mapfloat(e);
    free(e->t);
    free(e->quad);
}

void resize(t_elem *e)
{
    e->map = get_map(e->width, e->height);
    create_2d_map(e);
    create_color(e);
    createQuadArray(e);
    init_state_quad(e);
}

void flat(t_elem *e)
{
    for (int y = 0; y < e->height; y += 1)
        for (int x = 0; x < e->width; x += 1)
            e->map[y][x] = 0.0;
}

int is_flat(t_elem *e)
{
    for (int y = 0; y < e->height; y += 1)
        for (int x = 0; x < e->width; x += 1)
            if (e->map[y][x] != 0.0)
                return (1);
    return (0);
}