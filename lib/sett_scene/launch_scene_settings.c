/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** launch_scene_settings
*/

#include "../../include/my_world.h"

void destroy_settings(t_button_set *settings)
{
    for (int i = 0; i < NBBUTSETT; i += 1) {
        sfTexture_destroy(settings[i].data->texture);
        sfSprite_destroy(settings[i].data->sprite);
        free(settings[i].data);
    }
    free(settings);
}

void change_display_set(t_button *data, int act, int posY)
{
    if (act == 0) {
        data->height = 128;
        data->width = 128;
    } else {
        data->height = 64;
        data->width = 64;
    }
    if (data->rank == 0)
        data->position.x = WIDTH - data->width - 100;
    else
        data->position.x = (WIDTH / 2) - data->width - 100;
    data->position.y = posY;
}

void diplay_settings(t_button_set *settings, t_res *res)
{
    for (int i = 0; i < NBBUTSETT; i += 1) {
        sfSprite_setPosition(settings[i].data->sprite, \
        settings[i].data->position);
        sfRenderWindow_drawSprite(res->window, settings[i].data->sprite, NULL);
    }
}

void analyse_settings(t_button_set *settings, t_res *res, t_elem *e)
{
    if (res->event.type == sfEvtMouseMoved)
        check_settings(settings, res->event.mouseMove);
    if (res->event.type == sfEvtMouseButtonPressed)
        click_scene(settings, res->event.mouseButton, e, res);
}

void update_settings(t_button_set *settings, int i, t_elem *e, t_res *res)
{
    t_state *tmp = e->button;
    if (settings[i].data->rank == 0) {
        e->scene = 0;
        for (int i = 0; i < NBBUTSETT; i += 1)
            settings[i].state = NONE;
        for (; tmp->next; tmp = tmp->next);
        tmp->state = NONE;
    }
    if (settings[i].data->rank == 1)
        sfRenderWindow_close(res->window);
    if (settings[i].data->rank == 2)
        save_set(e);
    if (settings[i].data->rank == 3)
        load_set(e);
}