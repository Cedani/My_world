/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main functions
*/

#include "include/my_world.h"

int check_exist(char *file)
{
    FILE *fp = NULL;
    int ok = 0;
    char *tmp = malloc(sizeof(*tmp) * (READ_SIZE + 1));

    file = my_strcat("./save/", file);
    file = my_strcat(file, ".legend");
    fp = fopen(file, "r");
    if (!fp)
        return (1);
    ok = fread(tmp, READ_SIZE, 1, fp);
    if (ok == 0)
        return (1);
    fclose (fp);
    return (0);
}

int main(void)
{
    t_elem *e = NULL;
    t_res *res = NULL;
    t_button_list *list = NULL;

    init_list(&list);
    init_res(&res);
    init_elem(&e);
    if (check_exist("auto") == 1)
        save(4, e);
    game_loop(e, res, list);
    destroy_state(e);
    save(4, e);
    sfRenderWindow_destroy(res->window);
    return (0);
}