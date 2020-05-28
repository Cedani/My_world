/*
** EPITECH PROJECT, 2020
** basing_functions
** File description:
** basing_functions
*/

#include "../../include/my_world.h"

void add_element(t_button_list **list, t_button *button)
{
    t_button_list *elem = malloc(sizeof(*elem));
    t_button_list *tmp = (*list);

    elem->data = button;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void remove_element(t_button_list **list, int position)
{
    t_button_list *tmp1 = NULL;
    t_button_list *tmp2 = (*list);
    t_button_list *tmp_to_free = NULL;

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

void insert_element(t_button_list **list, int position, t_button *button)
{
    t_button_list *elem = malloc(sizeof(*elem));
    t_button_list *tmp1 = (*list);
    t_button_list *tmp2 = (*list);

    elem->data = button;
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