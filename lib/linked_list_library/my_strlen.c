/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_strlen
*/

#include "../../include/my_world.h"

void my_memset(char *str, int nb)
{
    for (int i = 0; i < nb; i += 1)
        str[i] = '\0';
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i += 1);
    return (i);
}