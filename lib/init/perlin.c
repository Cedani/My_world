/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** init_square
*/

#include "../../include/my_world.h"

float float_rand(float max, float min)
{
    float scale = rand() / (float) RAND_MAX;
    return (min + scale * (max - min));
}

void smoother(float **str, float **tmp, float around, float smooth)
{
    for (int k = 0; k < 25; k++) {
        for (int i = 1; i < 150 - 1; i++) {
            around_str(str, around, smooth, i, tmp);
        }
        smoother_2(str, tmp);
    }
}

void average(float **str, float **tmp)
{
    for (int k = 0; k < 100; k++) {
        average_2(str, tmp, k);
    }
}

void init_2d_floats(float **str, float **tmp, int freq_max, int freq_min)
{
    int pic = rand() % (freq_max - freq_min) + freq_min;
    for (int i = 0; i < 150; i++) {
        str[i] = malloc(sizeof(float) * (150 + 1));
        tmp[i] = malloc(sizeof(float) * (150 + 1));
        for (int j = 0; j < 150; j++)
            str[i][j] = 0;
    }
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            if (!pic) {
                str[i][j] = float_rand(500, -500);
                pic = rand() % (freq_max - freq_min) + freq_min;
            }
            pic -= 1;
        }
    }
}

float **map_generator(float height_max, \
    float height_min, int freq_max, int freq_min)
{
    srand(time(NULL));
    float **str;
    float **tmp;
    int pic = rand() % (freq_max - freq_min) + freq_min;
    float smooth = 0.01;
    float around = 0;

    str = malloc(sizeof(float *) * (150 + 1));
    tmp = malloc(sizeof(float *) * (150 + 1));
    init_2d_floats(str, tmp, freq_max, freq_min);
    for (int i = 0; i < 150; i++)
        for (int j = 0; j < 150; j++)
            tmp[i][j] = str[i][j];
    smoother(str, tmp, around, smooth);
    average(str, tmp);
    return (str);
}