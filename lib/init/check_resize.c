/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** check_resize
*/

#include "../../include/my_world.h"

void resizer(t_elem *e, int pos)
{
    if (pos == 3 && e->width <= LIMUP) {
        e->width += 1;
        e->height += 1;
        resize(e);
    }
    if (pos == 4 && e->width >= LIMDOWN) {
        e->width -= 1;
        e->height -= 1;
        resize(e);
    }
    if (pos == 5)
        e->scene = 1;
}

void check_size(t_elem *e, t_button_list *l)
{
    t_state *tmp = e->button;

    for (; l->data->rank != 3; l = l->next)
        tmp = tmp->next;
    if (e->width <= LIMUP && tmp->state != OVER)
        tmp->state = NONE;
    tmp = tmp->next;
    if (e->width >= LIMDOWN && tmp->state != OVER)
        tmp->state = NONE;
}