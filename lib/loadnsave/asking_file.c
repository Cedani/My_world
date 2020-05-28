/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** asking_file
*/

#include "../../include/my_world.h"

int check_good_file(char *buffer, int n)
{
    if (n == -1)
        return (1);
    if (my_strlen(buffer) > 2)
        return (1);
    if (buffer[0] - 48 > 3)
        return (1);
    return (0);
}

int check_good_load(char *buffer, int n)
{
    FILE *fp = NULL;
    int ok = 0;
    char *tmp = malloc(sizeof(*tmp) * READ_SIZE + 1);

    if (n == -1)
        return (0);
    buffer[1] = '\0';
    buffer = my_strcat("./save/", buffer);
    buffer = my_strcat(buffer, ".legend");
    fp = fopen(buffer, "r");
    if (!fp) {
        fwrite("file does not exist\n", 20, 1, stdout);
        return (1);
    }
    ok = fread(tmp, READ_SIZE, 1, fp);
    if (ok == 0) {
        fwrite("empty file\n", 11, 1, stdout);
        return (1);
    }
    fclose (fp);
    return (0);
}

int asking_load(void)
{
    int nb = 0;
    char *buffer = NULL;
    char *quest = "which file do you want to load?: ";
    size_t n = 0;

    fwrite(quest, my_strlen(quest), 1, stdout);
    n = getline(&buffer, &n, stdin);
    while (n != -1 && check_good_file(buffer, n) == 1
            || check_good_load(buffer, n) == 1) {
        fwrite("\n", 1, 1, stdout);
        fwrite(quest, my_strlen(quest), 1, stdout);
        n = getline(&buffer, &n, stdin);
    }
    if (n == -1)
        return (-1);
    fwrite("\n", 1, 1, stdout);
    return (buffer[0] - 48);
}

int asking_save(void)
{
    int nb = 0;
    char *buffer = NULL;
    char *quest = "In which file do yo want to save?: ";
    size_t n = 0;

    fwrite(quest, my_strlen(quest), 1, stdout);
    n = getline(&buffer, &n, stdin);
    while (check_good_file(buffer, n) == 1) {
        fwrite("\n", 1, 1, stdout);
        fwrite(quest, my_strlen(quest), 1, stdout);
        n = getline(&buffer, &n, stdin);
    }
    return (buffer[0] - 48);
}