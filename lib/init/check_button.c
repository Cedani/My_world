/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** check_button
*/

#include "../../include/my_world.h"

void change_display(t_button *data, int act, int posY)
{
    if (act == 0) {
        data->height = 128;
        data->width = 128;
    } else {
        data->height = 64;
        data->width = 64;
    }
    data->position.x = WIDTH - data->width - 100;
    data->position.y = posY;
}

void check_click(t_button_list *l, t_elem *e, sfMouseButtonEvent button)
{
    t_state *tmp = e->button;

    for (; l; l = l->next) {
        if ((button.x >= l->data->position.x
            && button.x <= l->data->position.x + l->data->width)
            && (button.y >= l->data->position.y
            &&  button.y <= l->data->position.y + l->data->height)) {
                check_down(&tmp->state, e, l->data->rank);
            }
        else if (tmp->state != ONCLICK)
            tmp->state = NONE;
        check_depth(e, l->data->rank);
        tmp = tmp->next;
    }
}

void check_other(STATEM *state, t_elem *e, int pos)
{
    if (pos == 2 && is_flat(e) == 1) {
        *state = ONCLICK;
        flat(e);
    }
    if (pos == 3 && e->width == LIMUP)
        *state = ONCLICK;
    if (pos == 4 && e->width == LIMDOWN)
        *state = ONCLICK;
    resizer(e, pos);
}

void check_down(STATEM *state, t_elem *e, int pos)
{
    if (pos == 1) {
        if (e->button->state == NONE)
            e->button->next->state = ONCLICK;
        if (e->button->state == ONCLICK) {
            e->button->next->state = ONCLICK;
            e->button->state = NONE;
        }
    } else if (pos == 0) {
        if (e->button->next->state == NONE)
            e->button->state = ONCLICK;
        if (e->button->next->state == ONCLICK) {
            e->button->state = ONCLICK;
            e->button->next->state = NONE;
        }
    }
    check_other(state, e, pos);
}

void check_depth(t_elem *e, int pos)
{
    if (pos == 0 && e->button->state == ONCLICK) {
        if (e->depth < 0)
            e->depth *= -1;
    }
    if (pos == 1 && e->button->next->state == ONCLICK) {
        if (e->depth > 0)
            e->depth *= -1;
    }
}