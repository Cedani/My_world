/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** save
*/

#include "../../include/my_world.h"

static const char *filepath[NBSAVE] = {
    "./save/1.legend",
    "./save/2.legend",
    "./save/3.legend",
    "./save/auto.legend"
};

void save_map(t_elem *e, FILE *fp)
{
    char *tmp = NULL;
    char *end = "e";
    char *n = "\n";
    char *s = " ";

    for (int y = 0; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            tmp = my_ftostr(e->map[y][x], 6);
            fwrite(tmp, my_strlen(tmp), 1, fp);
            fwrite(s, my_strlen(s), 1, fp);
        }
        fwrite(n, my_strlen(n), 1, fp);
    }
    fwrite(end, 1, my_strlen(end), fp);
    fwrite(n, 1, my_strlen(n), fp);
}

void save_map2(t_elem *e, FILE *fp)
{
    char *tmp = NULL;
    char *end = "e";
    char *n = "\n";
    char *s = " ";
    char *h = "#";

    for (int y; y < e->height; y += 1) {
        for (int x = 0; x < e->width; x += 1) {
            tmp = my_ftostr(e->map2[y][x].x, 6);
            fwrite(tmp, my_strlen(tmp), 1, fp);
            fwrite(h, my_strlen(h), 1, fp);
            tmp = my_ftostr(e->map2[y][x].y, 6);
            fwrite(tmp, my_strlen(tmp), 1, fp);
            fwrite(s, my_strlen(s), 1, fp);
        }
        fwrite(n, 1, my_strlen(n), fp);
    }
    fwrite(end, 1, my_strlen(end), fp);
    fwrite(n, 1, my_strlen(n), fp);
}

void save_info(t_elem *e, FILE *fp)
{
    char *tmp = malloc(sizeof(char));
    char *s = " ";

    tmp = my_ftostr((float)e->width, 0);
    fwrite(tmp, my_strlen(tmp), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
    tmp = my_ftostr((float)e->height, 0);
    fwrite(tmp, my_strlen(tmp), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
    tmp = my_ftostr((float)e->ang.x, 2);
    fwrite(tmp, my_strlen(tmp), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
    tmp = my_ftostr((float)e->ang.y, 2);
    fwrite(tmp, my_strlen(tmp), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
    tmp = my_ftostr((float)e->ang.z, 2);
    fwrite(tmp, my_strlen(tmp), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
    info_suite(e, fp);
}

void save_color(t_elem *e, FILE *fp)
{
    char *tmp = NULL;
    char *end = "e";
    char *n = "\n";
    char *s = " ";

    for (int i = 0; i < pow(e->height - 1, 2); i += 1) {
        if (e->t[i].b == 255)
            tmp = my_ftostr(1, 0);
        if (e->t[i].g == 255)
            tmp = my_ftostr(2, 0);
        if (e->t[i].r == 255 && e->t[i].g == 0)
            tmp = my_ftostr(3, 0);
        if (e->t[i].g == 255 && e->t[i].r == 255)
            tmp = my_ftostr(4, 0);
        fwrite(tmp, my_strlen(tmp), 1, fp);
        fwrite(s, my_strlen(s), 1, fp);
    }
    fwrite(n, my_strlen(n), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
}

void save(int nb_save, t_elem *e)
{
    FILE *fp = fopen(filepath[nb_save - 1], "w+");

    save_info(e, fp);
    save_map(e, fp);
    save_map2(e, fp);
    save_color(e, fp);
    fclose(fp);
}