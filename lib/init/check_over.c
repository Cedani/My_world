/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** check_over
*/

#include "../../include/my_world.h"

void reset_all(t_elem *e)
{
    for (int i = 0; i < pow(e->width - 1, 2); i += 1) {
        e->quad[i].state = NONE;
        e->quad[i].next = NULL;
    }
}

void destroy_vertex(t_elem *e)
{
    free(e->v_quad);
}

void destroy_mapfloat(t_elem *e)
{
    for (int i = 0; i < e->height; i += 1)
        free(e->map[i]);
    free(e->map);
}

void destroy_mapvect(t_elem *e)
{
    for (int i = 0; i < e->height; i += 1)
        free(e->map2[i]);
}

void destroy_elem(t_elem *e)
{
    destroy_vertex(e);
    destroy_mapfloat(e);
    destroy_mapvect(e);
    free(e->t);
}
