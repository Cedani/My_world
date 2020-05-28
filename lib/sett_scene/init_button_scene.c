/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_button_scene
*/

#include "../../include/my_world.h"

static const char *filepath[NBBUTSETT] = {
    "./image/cancel.png",
    "./image/exit.png",
    "./image/save.png",
    "./image/load.png"
};

static const char *over[NBBUTSETT] = {
    "./image/cancel_over.png",
    "./image/exit_over.png",
    "./image/save_over.png",
    "./image/load_over.png"
};

void init_cancel(t_button_set *cancel)
{
    cancel->data->texture = sfTexture_createFromFile(filepath[0], NULL);
    cancel->data->sprite = sfSprite_create();
    sfSprite_setTexture(cancel->data->sprite, cancel->data->texture, sfFalse);
    cancel->data->height = 64;
    cancel->data->width = 64;
    cancel->data->position.x = WIDTH - cancel->data->width - 100;
    cancel->data->position.y = 0;
}

void middle_button(t_button_set *button, int i)
{
    static int posY = 100;

    button->data->texture = sfTexture_createFromFile(filepath[i], NULL);
    button->data->sprite = sfSprite_create();
    sfSprite_setTexture(button->data->sprite, button->data->texture, sfFalse);
    button->data->height = 64;
    button->data->width = 64;
    button->data->position.x = (WIDTH / 2) - button->data->width - 100;
    button->data->position.y = posY;
    posY += 128;
}

t_button_set *init_settings(void)
{
    t_button_set *settings = malloc(sizeof(*settings) * NBBUTSETT);

    for (int i = 0; i < NBBUTSETT; i += 1) {
        settings[i].data = malloc(sizeof(t_button));
        if (i == 0)
            init_cancel(&settings[i]);
        else
            middle_button(&settings[i], i);
        settings[i].state = NONE;
        settings[i].data->rank = i;
    }
    return (settings);
}

void check_state(t_button_set *settings)
{
    int posY = 100;

    for (int i = 0; i < NBBUTSETT; i += 1) {
        sfTexture_destroy(settings[i].data->texture);
        sfSprite_destroy(settings[i].data->sprite);
        if (settings[i].state == OVER) {
            change_display_set(settings[i].data, 0, posY);
            settings[i].data->texture = sfTexture_createFromFile(over[i], NULL);
        } else {
            change_display_set(settings[i].data, 1, posY);
            settings[i].data->texture = sfTexture_createFromFile(filepath[i], \
            NULL);
        }
        if (i != 0)
            posY += 128;
        settings[i].data->sprite = sfSprite_create();
        sfSprite_setTexture(settings[i].data->sprite, \
        settings[i].data->texture, sfFalse);
    }
}

void check_settings(t_button_set *set, sfMouseMoveEvent button)
{
    for (int i = 0; i < NBBUTSETT; i += 1) {
        if ((button.x >= set[i].data->position.x
            && button.x <= set[i].data->position.x + set[i].data->width)
            && (button.y >= set[i].data->position.y
            &&  button.y <= set[i].data->position.y + set[i].data->height)
            && set[i].state != ONCLICK) {
                set[i].state = OVER;
        } else
            set[i].state = NONE;
    }
}