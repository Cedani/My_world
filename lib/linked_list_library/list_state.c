/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** list_state
*/

#include "../../include/my_world.h"

void add_state_element(t_state **list, STATEM state)
{
    t_state *elem = malloc(sizeof(*elem));
    t_state *tmp = (*list);

    elem->state = state;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void remove_state_element(t_state **list, int position)
{
    t_state *tmp1 = NULL;
    t_state *tmp2 = (*list);
    t_state *tmp_to_free = NULL;

    if (position == 1) {
        tmp1 = (*list);
        (*list) = (*list)->next;
        free(tmp1);
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp2 = tmp2->next;
    tmp1 = tmp2->next->next;
    tmp_to_free = tmp2->next;
    tmp2->next = tmp1;
    free(tmp_to_free);
}

void insert_state_element(t_state **list, int position, STATEM state)
{
    t_state *elem = malloc(sizeof(*elem));
    t_state *tmp1 = (*list);
    t_state *tmp2 = (*list);

    elem->state = state;
    if (position == 1) {
        elem->next = (*list);
        (*list) = elem;
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp1 = tmp1->next;
    for (int i = 0; i < position - 1; i += 1) {
        tmp2 = tmp2->next;
        if (i < position - 2 && tmp2 == NULL)
            exit(84);
    }
    tmp1->next = elem;
    elem->next = tmp2;
}