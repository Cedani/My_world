/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_revstr
*/

#include "../../include/my_world.h"

char *my_revstr(char *str)
{
    char *ret = malloc(sizeof(*ret) * (my_strlen(str)));
    int j = my_strlen(str) - 1;
    int i = 0;
    char tmp = 0;

    my_memset(ret, my_strlen(str));
    for (; j >= 0; j -= 1, i += 1)
        ret[i] = str[j];
    ret[i] = '\0';
    return (ret);
}