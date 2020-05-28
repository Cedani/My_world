/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_suite
*/

#include "../../include/my_world.h"

void init_suite(t_elem **e)
{
    (*e)->quad = NULL;
    create_2d_map(*e);
    create_color((*e));
    createQuadArray(*e);
    init_state_quad((*e));
    init_state_button(*e);
}

void check_over(t_elem *e)
{
    load_color_save(e);
    for (int i = 0; i < pow(e->height - 1, 2); i += 1) {
        if (e->quad[i].state == OVER)
            e->t[i] = sfRed;
        else
            e->t[i] = e->save[i];
    }
}

float distanceMove(sfMouseMoveEvent b, sfVector2f po2)
{
    float dist = sqrt(pow(b.x - po2.x, 2) + pow(b.y - po2.y, 2));
    return (dist);
}

void check_state_map(t_elem *e, int n)
{
    t_state *tmp = e->quad;
    for (int i = 0; i < n - 1; i += 1)
        tmp = tmp->next;
    tmp->state = OVER;
}

void update_quad_state(t_elem *e, sfMouseMoveEvent b)
{
    sfVector2f mid = midpoint(e->map2[0][0], e->map2[1][1]);
    float check = 0;
    float check2 = distanceMove(b, mid);
    int k = 0;
    int n = 0;

    for (int y = 0; y < e->height; y += 1)
        for (int x = 0; x < e->width; x += 1) {
            if (x + 1 < e->width && y + 1 < e->height) {
                mid = midpoint(e->map2[y][x], e->map2[y + 1][x + 1]);
                check = distanceMove(b, mid);
                k += 1;
            }
            if (check2 >= check) {
                n = k;
                check2 = check;
            }
        }
    e->quad[n - 1].state = OVER;
}