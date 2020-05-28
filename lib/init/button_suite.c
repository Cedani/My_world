/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** button_suite
*/

#include "../../include/my_world.h"

void change_flat(t_elem *e, t_button_list *l)
{
    t_state *tmp = e->button;
    if (is_flat(e) == 0)
        return;
    for (; l->data->rank != 2; l = l->next)
        tmp = tmp->next;
    tmp->state = NONE;
}