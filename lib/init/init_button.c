/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_button
*/

#include "../../include/my_world.h"

static const char *filepath[NBBUTTON] = {
    "./image/up.png",
    "./image/down.png",
    "./image/zero.png",
    "./image/plus.png",
    "./image/minus.png",
    "./image/gear.png"
};

static const char *over[NBBUTTON] = {
    "./image/up_over.png",
    "./image/down_over.png",
    "./image/zero_over.png",
    "./image/plus_over.png",
    "./image/minus_over.png",
    "./image/gear_over.png"
};

static const char *click[NBBUTTON] = {
    "./image/verified.png",
    "./image/verified.png",
    "./image/zero_click.png",
    "./image/plus_limit.png",
    "./image/minus_limit.png",
    "./image/gear.png"
};

void init_button(t_button **button, int i)
{
    static int posY = 0;

    *button = malloc(sizeof(t_button));
    (*button)->texture = sfTexture_createFromFile(filepath[i], NULL);
    (*button)->sprite = sfSprite_create();
    sfSprite_setTexture((*button)->sprite, (*button)->texture, sfFalse);
    (*button)->height = 64;
    (*button)->width = 64;
    (*button)->position.x = WIDTH - (*button)->width - 100;
    (*button)->position.y = posY;
    posY += 128;
}

void init_list(t_button_list **list)
{
    for (int i = 0; i < NBBUTTON; i += 1) {
        t_button *button = NULL;
        init_button(&button, i);
        button->rank = i;
        add_element(list, button);
    }
}

void spr_todisplay(t_button_list *list, t_elem *e)
{
    static int posY = 0;
    t_state *tmp = e->button;

    for (int i = 0; i < NBBUTTON; i += 1, posY += 128) {
        sfTexture_destroy(list->data->texture);
        sfSprite_destroy(list->data->sprite);
        if (tmp->state == OVER) {
            change_display(list->data, 0, posY);
            list->data->texture = sfTexture_createFromFile(over[i], NULL);
        }
        else if (tmp->state == ONCLICK){
            change_display(list->data, 1, posY);
            list->data->texture = sfTexture_createFromFile(click[i], NULL);
        } else {
            change_display(list->data, 1, posY);
            list->data->texture = sfTexture_createFromFile(filepath[i], NULL);
        }
        list->data->sprite = sfSprite_create();
        sfSprite_setTexture(list->data->sprite, list->data->texture, sfFalse);
        list = list->next;
        tmp = tmp->next;
    }
    posY = 0;
}

void display_button(t_button_list *list, t_res *res, t_elem *e)
{
    spr_todisplay(list, e);
    for (; list; list = list->next) {
        sfSprite_setPosition(list->data->sprite, list->data->position);
        sfRenderWindow_drawSprite(res->window, list->data->sprite, NULL);
    }
}

void check_button(t_button_list *l, t_elem *e, sfMouseMoveEvent button)
{
    t_state *tmp = e->button;

    for (; l; l = l->next) {
        if ((button.x >= l->data->position.x
            && button.x <= l->data->position.x + l->data->width)
            && (button.y >= l->data->position.y
            &&  button.y <= l->data->position.y + l->data->height)
            && tmp->state != ONCLICK) {
                tmp->state = OVER;
            }
        else if (tmp->state != ONCLICK)
            tmp->state = NONE;
        tmp = tmp->next;
    }
}