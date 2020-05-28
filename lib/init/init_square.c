/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_square
*/

#include "../../include/my_world.h"

void create_quad(t_elem *e, sfVector2i p, int i, sfColor c)
{
    sfVertex vertex1 = {.position = e->map2[p.y][p.x], .color = c};
    sfVertex vertex2 = {.position = e->map2[p.y][p.x + 1], .color = c};
    sfVertex vertex3 = {.position = e->map2[p.y + 1][p.x + 1], .color = c};
    sfVertex vertex4 = {.position = e->map2[p.y + 1][p.x], .color = c};

    sfVertexArray_clear(e->v_quad[i]);
    sfVertexArray_append(e->v_quad[i], vertex1);
    sfVertexArray_append(e->v_quad[i], vertex2);
    sfVertexArray_append(e->v_quad[i], vertex3);
    sfVertexArray_append(e->v_quad[i], vertex4);
    sfVertexArray_setPrimitiveType(e->v_quad[i], sfQuads);
}

void createQuadArray(t_elem *e)
{
    int i = 0;

    e->v_quad = malloc(sizeof(sfVertexArray *) * pow(e->width - 1, 2));
    for (int y = 0; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            if (x + 1 < e->width && y + 1 < e->height) {
                e->v_quad[i] = sfVertexArray_create();
                create_quad(e, (sfVector2i){x, y}, i, e->t[i]);
                i += 1;
            }
        }
    }
}

void draw_map(t_elem *e, sfRenderWindow *w)
{
    int lim = pow(e->width - 1, 2);
    for (int i = 0; i < lim; i += 1) {
        sfRenderWindow_drawVertexArray(w, e->v_quad[i], NULL);
        sfVertexArray_destroy(e->v_quad[i]);
    }
}

int highest(int p1, int p2, int p3, int p4)
{
    int array[4] = {p1, p2, p3, p4};

    bubble_sort(array);
    return (array[0]);
}

void create_color(t_elem *e)
{
    int high = 0;
    int i = 0;

    e->t = malloc(sizeof(*e->t) * pow(e->width - 1, 2));
    for (int y = 0; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            if (x + 1 < e->width && y + 1 < e->height) {
                high = highest(e->map[y][x], e->map[y + 1][x], \
                e->map[y + 1][x + 1], e->map[y][x + 1]);
                check_color(e, i, high);
                i += 1;
            }
        }
    }
}