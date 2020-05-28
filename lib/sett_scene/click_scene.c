/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** click_scene
*/

#include "../../include/my_world.h"

void click_scene(t_button_set *set, sfMouseButtonEvent button, \
    t_elem *e, t_res *res)
{
    for (int i = 0; i < NBBUTSETT; i += 1) {
        if ((button.x >= set[i].data->position.x
            && button.x <= set[i].data->position.x + set[i].data->width)
            && (button.y >= set[i].data->position.y
            &&  button.y <= set[i].data->position.y + set[i].data->height)) {
                update_settings(set, i, e, res);
        }
    }
}

void save_set(t_elem *e)
{
    save(asking_save(), e);
}

void load_set(t_elem *e)
{
    int ok = asking_load();

    if (ok != -1)
        load(ok, e);
}