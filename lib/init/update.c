/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** update
*/

#include "../../include/my_world.h"

void update_map(t_elem *e, t_button_list *l)
{
    check_over(e);
    update_2D_map(e);
    createQuadArray(e);
}

void create_window(sfRenderWindow **window, int width, int height)
{
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    *window = sfRenderWindow_create(mode, "My_world", sfDefaultStyle, NULL);
}

void init_elem(t_elem **e)
{
    (*e) = malloc(sizeof(t_elem));
    (*e)->inc = 0.0;
    (*e)->t = NULL;
    (*e)->map2 = NULL;
    (*e)->v_quad = NULL;
    (*e)->quad = NULL;
    (*e)->button = NULL;
    (*e)->height = 110;
    (*e)->width = 110;
    (*e)->ang.x = 45.0;
    (*e)->ang.y = 35.0;
    (*e)->ang.z = 10;
    (*e)->trans.x = 960;
    (*e)->trans.y = 540;
    (*e)->depth = 10;
    (*e)->scene = 0;
    (*e)->map = get_map((*e)->width, (*e)->height);
    init_suite(e);
}

void init_res(t_res **res)
{
    (*res) = malloc(sizeof(t_res));
    create_window(&(*res)->window, 1920, 1080);
}

void change(t_elem *e, int i, int j)
{
    e->map[i][j] += e->depth;
    e->map[i + 1][j] += e->depth;
    e->map[i][j + 1] += e->depth;
    e->map[i + 1][j + 1] += e->depth;
}