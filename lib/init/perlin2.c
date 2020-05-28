/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_square
*/

#include "../../include/my_world.h"

void around_str(float **str, float around, float smooth, int i, float **tmp)
{
    for (int j = 1; j < 150 - 1; j++) {
        around = fabs(str[i-1][j]) > fabs(around) ? str[i-1][j] : around;
        around = fabs(str[i+1][j]) > fabs(around) ? str[i+1][j] : around;
        around = fabs(str[i][j-1]) > fabs(around) ? str[i][j-1] : around;
        around = fabs(str[i][j+1]) > fabs(around) ? str[i][j+1] : around;
        around = fabs(str[i][j]) > fabs(around) ? str[i][j] : around;
        tmp[i][j] = around > 0 ? around - smooth : around + smooth;
        around = 0;
    }    
}

void average_2(float **str, float **tmp, int k)
{
    for (int i = 1; i < 150 - 1; i++)
        for (int j = 1; j < 150 - 1; j++)
            tmp[i][j] = (str[i][j] + str[i+1][j] + str[i-1][j] 
            + str[i][j+1] + str[i][j-1]) / 5;
    for (int i = 0; i < 150; i++)
        for (int j = 0; j < 150; j++)
            str[i][j] = tmp[i][j];
}

void smoother_2(float **str, float **tmp)
{
    for (int i = 0; i < 150; i++)
        for (int j = 0; j < 150; j++)
            str[i][j] = tmp[i][j];
}

void check_color(t_elem *e, int i, int highest)
{
    if (highest > 0 && highest <= 200)
        e->t[i] = sfGreen;
    else if (highest > 200)
        e->t[i] = sfYellow;
    else
        e->t[i] = sfBlue;
}

void bubble_sort(int point[4])
{
    int swapped = 0;
    int tmp = 0;

    for (int i = 0; i < 3; i += 1) {
        if (point[i] < point[i + 1]) {
            tmp = point[i];
            point[i] = point[i + 1];
            point[i + 1] = tmp;
            swapped = 1;
        }
    }
    if (swapped == 1)
        bubble_sort(point);
}