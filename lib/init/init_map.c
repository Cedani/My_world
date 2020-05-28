/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_map
*/

#include "../../include/my_world.h"

float **get_map(int width, int height)
{
    float **map = map_generator(100, -100, 2222, 1222);
    return (map);
}

sfVector2f trans32(sfVector3f po, t_elem *e)
{
    sfVector2f p = {0, 0};

    p.x = cosf(e->ang.x) * po.x - sinf(e->ang.x) * po.y + e->trans.x;
    p.y = sinf(e->ang.y) * po.y + sinf(e->ang.y) * po.x - po.z + e->trans.y;
    return (p);
}

void create_2d_map(t_elem *e)
{
    e->map2 = malloc(sizeof(*e->map2) * e->height);
    for (int y = 0; y < e->height; y += 1) {
        e->map2[y] = malloc(sizeof(sfVector2f) * e->width);
        for (int x = 0; x < e->width; x += 1) {
            sfVector3f po = {x * e->ang.z, y * e->ang.z, e->map[y][x]};
            e->map2[y][x] = trans32(po, e);
        }
    }
}