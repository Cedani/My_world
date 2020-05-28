/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_atof
*/

#include "../../include/my_world.h"

int nb_afvir(char *str)
{
    int i = 0;
    int nb = 0;
    int save = 0;

    for (; str[i] && (str[i] < '0' || str[i] > '9'); i += 1);
    for (; str[i] != ' ' && str[i] && str[i] != '.'; i += 1);
    if (str[i] == ' ')
        return (0);
    for (; str[i] && str[i] == '.'; i += 1);
    for (; i != 0 && str[i] && str[i] >= '0' && str[i] <= '9'; i += 1)
        nb += 1;
    return (nb);
}

int nb_bevir(char *str)
{
    int i = 0;
    int nb = 0;

    for (; str[i] && (str[i] < '0' || str[i] > '9'); i += 1);
    for (; str[i] && (str[i] >= '0' && str[i] <= '9'); i += 1)
        nb += 1;
    return (nb);
}

int jump_num(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    if (c == '-')
        return (0);
    if (c == '.')
        return (0);
    return (1);
}

void give_nb(char **str, int *i)
{
    int k = *i;

    for (; jump_num(str[0][0]) == 0; str[0] += 1);
    for (;str[0][0] && jump_num(str[0][0]) != 0; str[0] += 1);
    *i += k;
}

float my_atof(char **str, int *k)
{
    int av = 0;
    int i = 0;
    int nb_total = nb_bevir(str[0]) + nb_afvir(str[0]);
    float ret = 0;

    for (; str[0][i] && (str[0][i] < '0' || str[0][i] > '9'); i += 1);
    for (; nb_total > 0; nb_total -= 1) {
        if (str[0][i] == '.')
            i += 1;
        ret += (str[0][i] - '0') * pow(10, nb_total);
        i += 1;
    }
    ret /= pow(10, nb_afvir(str[0]) + 1);
    if (str[0][0] == '-')
        ret *= -1;
    give_nb(str, &av);
    *k = av + 1;
    return (ret);
}