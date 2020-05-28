/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** save_suite
*/

#include "../../include/my_world.h"

void info_suite(t_elem *e, FILE *fp)
{
    char *tmp = NULL;
    char *end = "e";
    char *n = "\n";
    char *s = " ";

    tmp = my_ftostr((float)e->trans.x, 2);
    fwrite(tmp, my_strlen(tmp), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
    tmp = my_ftostr((float)e->trans.y, 2);
    fwrite(tmp, my_strlen(tmp), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
    tmp = my_ftostr((float)e->depth, 0);
    fwrite(tmp, my_strlen(tmp), 1, fp);
    fwrite(s, my_strlen(s), 1, fp);
    fwrite(end, my_strlen(end), 1, fp);
    fwrite(n, my_strlen(n), 1, fp);
}