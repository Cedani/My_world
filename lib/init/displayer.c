/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** displayer
*/

#include "../../include/my_world.h"

static const char *filepath[2] = {
    "./image/helper.png",
    "./image/settings.png"
};

void analyse_scene(t_elem *e, t_res *res, t_button_list *list, t_button_set *s)
{
    if (res->event.type == sfEvtClosed)
        sfRenderWindow_close(res->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(res->window);
    if (e->scene == 0)
        analyse_event(res, e, list);
    else if (e->scene == 1) {
        analyse_settings(s, res, e);
    }
}

void updater(t_elem *e, t_res *res, t_button_list *list, t_button_set **s)
{
    sfTexture *help = sfTexture_createFromFile(filepath[e->scene], NULL);
    sfSprite *help_sp = sfSprite_create();
    sfVector2f pos = {0, 700};
    sfSprite_setTexture(help_sp, help, sfTrue);
    sfRenderWindow_clear(res->window, sfWhite);
    sfRenderWindow_clear(res->window, sfWhite);

    if (e->scene == 0) {
        update_map(e, list);
        draw_map(e, res->window);
        display_button(list, res, e);
    }
    else if (e->scene == 1) {
        check_state(s[0]);
        diplay_settings(s[0], res);
    }
    if (e->scene == 1 && s[0] == NULL)
        s[0] = init_settings();
    sfRenderWindow_drawSprite(res->window, help_sp, NULL);
    sfRenderWindow_display(res->window);
}

void game_loop(t_elem *e, t_res *res, t_button_list *list)
{
    t_button_set *set = init_settings();

    while (sfRenderWindow_isOpen(res->window)) {
        while (sfRenderWindow_pollEvent(res->window, &res->event))
            analyse_scene(e, res, list, set);
        updater(e, res, list, &set);
    }
}