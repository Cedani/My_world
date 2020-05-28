/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_strcat
*/

#include "../../include/my_world.h"

char *my_strcat(char *s1, char *s2)
{
    char *ret = malloc(sizeof(*ret) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;
    int j = 0;

    for (; s1[i]; i += 1)
        ret[i] = s1[i];
    for (; s2[j]; j += 1)
        ret[j + i] = s2[j];
    ret[j + i] = '\0';
    return (ret);
}