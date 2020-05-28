/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** load_suite
*/

#include "../../include/my_world.h"

void load_suite(char **str, t_elem *e)
{
    int av = 0;

    e->trans.x = my_atof(str, &av);
    e->trans.y = my_atof(str, &av);
    e->depth = (int)my_atof(str, &av);
}

char *all_file(FILE *fp)
{
    char *buffer = malloc(sizeof(char) * 2);
    char *tmp = malloc(sizeof(char) * (READ_SIZE + 1));
    int k = -2;

    my_memset(buffer, 2);
    tmp[READ_SIZE] = '\0';
    for (; k != 0; k += 0) {
        k = fread(tmp, READ_SIZE, 1, fp);
        tmp[READ_SIZE] = '\0';
        if (k > 0)
            buffer = my_strcat(buffer, tmp);
    }
    return (buffer);
}

void init(t_elem *e)
{
    e->map = NULL;
    e->map2 = NULL;
    e->t = NULL;
}

void load_color(char **str, t_elem *e)
{
    int av = 0;
    int col = 0;

    e->t = malloc(sizeof(sfColor) * pow(e->width - 1, 2));
    for (int i = 0; i < pow(e->width - 1, 2); i += 1) {
        col = (int)my_atof(str, &av);
        if (col == 1)
            e->t[i] = sfBlue;
        else if (col == 2)
            e->t[i] = sfGreen;
        else
            e->t[i] = sfRed;
    }
}