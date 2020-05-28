/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_window
*/

#include "../../include/my_world.h"

void update_2D_map(t_elem *e)
{
    for (int y = 0; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            float test_x = (x * e->ang.z);
            float test_y = y * e->ang.z;
            float test_z = e->map[y][x] * e->ang.z * 0.04;
            float gi_x = (test_x - (e->width / 2 * e->ang.z)) * cosf(e->inc) \
            + (test_y - (e->height / 2 * e->ang.z)) * sinf(e->inc);
            float gi_y = (test_y - (e->height / 2 * e->ang.z)) * cosf(e->inc) \
            - (test_x - (e->width / 2 * e->ang.z)) * sinf(e->inc);
            sfVector3f po = {gi_x, gi_y, test_z};
            e->map2[y][x] = trans32(po, e);
        }
    }
}

sfVector2f midpoint(sfVector2f po1, sfVector2f po2)
{
    sfVector2f mid = {0.0};

    mid.x = (po1.x + po2.x) / 2;
    mid.y = (po1.y + po2.y) / 2;
    return (mid);
}

float distance(sfMouseButtonEvent b, sfVector2f po2)
{
    float dist = sqrt(pow(b.x - po2.x, 2) + pow(b.y - po2.y, 2));
    return (dist);
}

void update_click(t_elem *e, sfMouseButtonEvent b)
{
    float check = 0;
    float check2 = 0;
    int i = 0;
    int j = 0;

    for (int y = 0; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            if (x == 0 && y == 0)
                check2 = distance(b, e->map2[y][x]);
            check = distance(b, e->map2[y][x]);
            if (check2 > check) {
                check2 = check;
                i = y;
                j = x;
            }
        }
    }
    e->map[i][j] += e->depth;
}

void update_quad(t_elem *e, sfMouseButtonEvent b)
{
    sfVector2f mid = midpoint(e->map2[0][0], e->map2[1][1]);
    float check = 0;
    float check2 = distance(b, mid);
    int i = 0;
    int j = 0;

    for (int y = 0; y < e->height; y += 1)
        for (int x = 0; x < e->width; x += 1) {
            if (x + 1 < e->width && y + 1 < e->height) {
                mid = midpoint(e->map2[y][x], e->map2[y + 1][x + 1]);
                check = distance(b, mid);
            }
            if (check2 > check) {
                check2 = check;
                i = y;
                j = x;
            }
        }
    change(e, i, j);
}