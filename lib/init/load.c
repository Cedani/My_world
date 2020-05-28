/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** load
*/

#include "../../include/my_world.h"

static const char *filepath[NBSAVE] = {
    "./save/1.legend",
    "./save/2.legend",
    "./save/3.legend",
    "./save/auto.legend"
};

char *read_file(char *str, FILE *fp)
{
    char *tmp = malloc(sizeof(char) * (READ_SIZE + 1));
    int k = -2;

    str = malloc(sizeof(char));
    str[0] = '\0';
    for (; k != 0 && tmp[0] != 'e'; k += 0) {
        k = fread(tmp, READ_SIZE, 1, fp);
        tmp[READ_SIZE] = '\0';
        if (k > 0 && tmp[0] != 'e' && tmp[0] != '\n')
            str = my_strcat(str, tmp);
    }
    return (str);
}

void load_info(char **str, t_elem *e)
{
    int av = 0;

    e->width = (int)my_atof(str, &av);
    e->height = (int)my_atof(str, &av);
    e->ang.x = my_atof(str, &av);
    e->ang.y = my_atof(str, &av);
    e->ang.z = my_atof(str, &av);
    load_suite(str, e);
}

void load_map(char **str, t_elem *e)
{
    int av = 0;

    e->map = malloc(sizeof(float *) * e->height);
    for (int y = 0; y < e->height; y += 1) {
        e->map[y] = malloc(sizeof(float) * e->width);
        for (int x = 0; x < e->width; x += 1) {
            e->map[y][x] = my_atof(str, &av);
        }
    }
}

void load_map2(char **str, t_elem *e)
{
    int av = 0;

    e->map2 = malloc(sizeof(sfVector2f *) * e->height);
    for (int y = 0; y < e->height; y += 1) {
        e->map2[y] = malloc(sizeof(sfVector2f) * e->width);
        for (int x = 0; x < e->width; x += 1) {
            e->map2[y][x].x = my_atof(str, &av);
            e->map2[y][x].y = my_atof(str, &av);
        }
    }
}

void load(int nb_save, t_elem *e)
{
    FILE *fp = fopen(filepath[nb_save - 1], "r");
    char *str = NULL;

    str = all_file(fp);
    load_info(&str, e);
    load_map(&str, e);
    load_map2(&str, e);
    load_color(&str, e);
    fclose (fp);
}