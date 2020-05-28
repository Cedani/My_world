/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** my_world
*/

#ifndef MY
#define MY
#define WIDTH  1920
#define HEIGHT  1080
#define PI  3.14159265359
#define NBBUTTON  6
#define LIMUP  149
#define LIMDOWN  100
#define NBSAVE  4
#define NBBUTSETT  4
#define READ_SIZE  5000
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/VertexArray.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

typedef enum {
    ONCLICK,
    OVER,
    NONE
}STATEM;

typedef struct s_state {
    STATEM state;
    struct s_state *next;
}t_state;


typedef struct s_res {
    sfRenderWindow *window;
    sfEvent event;
}t_res;

typedef struct s_button {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    int height;
    int width;
    int rank;
}t_button;

typedef struct s_elem {
    float **map;
    sfVector2f **map2;
    sfVertexArray **v_quad;
    sfVector3f ang;
    float inc;
    int depth;
    sfVector2f trans;
    t_state *quad;
    t_state *button;
    sfColor *t;
    sfColor *save;
    int scene;
    int width;
    int height;
}t_elem;

typedef struct s_button_list {
    t_button *data;
    struct s_button_list *next;
}t_button_list;

typedef struct s_button_set {
    t_button *data;
    STATEM state;
}t_button_set;

void create_2d_map(t_elem *e);
void createlineArrayy(t_elem *e);
float **get_map(int width, int height);
void createQuadArray(t_elem *e);
void analyse_event(t_res *res, t_elem *e, t_button_list *l);
void remove_state_element(t_state **list, int position);
void init_elem(t_elem **e);
void init_res(t_res **res);
void update_map(t_elem *e, t_button_list *l);
void draw_map(t_elem *e, sfRenderWindow *w);
sfVector2f trans32(sfVector3f po, t_elem *e);
void update_2D_map(t_elem *e);
void update_click(t_elem *e, sfMouseButtonEvent button);
void analyse_keyboard_event(t_res *res, t_elem *e);
void add_element(t_button_list **list, t_button *button);
void remove_element(t_button_list **list, int position);
void init_list(t_button_list **list);
void display_button(t_button_list *list, t_res *res, t_elem *e);
void add_state_element(t_state **list, STATEM state);
void init_state_quad(t_elem *e);
void init_state_button(t_elem *e);
void check_button(t_button_list *l, t_elem *e, sfMouseMoveEvent button);
void update_quad(t_elem *e, sfMouseButtonEvent b);
void change(t_elem *e, int i, int j);
void create_color(t_elem *e);
void init_suite(t_elem **e);
int is_inmap(t_elem *e, sfMouseMoveEvent b);
sfVector2f midpoint(sfVector2f po1, sfVector2f po2);
float distance(sfMouseButtonEvent b, sfVector2f po2);
void update_quad_state(t_elem *e, sfMouseMoveEvent b);
void check_over(t_elem *e);
void reset_all(t_elem *e);
int is_inmap_button(t_elem *e, sfMouseButtonEvent b);
void change_display(t_button *data, int act, int posY);
void check_click(t_button_list *l, t_elem *e, sfMouseButtonEvent button);
void check_down(STATEM *state, t_elem *e, int pos);
void check_depth(t_elem *e, int pos);
void destroy_state(t_elem *e);
void destroy_vertex(t_elem *e);
void destroy_mapfloat(t_elem *e);
void flat(t_elem *e);
void destroy_mapvect(t_elem *e);
int is_flat(t_elem *e);
void change_flat(t_elem *e, t_button_list *l);
void resize(t_elem *e);
void destroyer_resize(t_elem *e);
void resizer(t_elem *e, int pos);
void check_size(t_elem *e, t_button_list *l);
float my_atof(char **str, int *k);
int my_strlen(char *str);
void my_memset(char *str, int nb);
char *my_revstr(char *str);
char *my_ftostr(float nb, int prec);
char *my_strcat(char *s1, char *s2);
void info_suite(t_elem *e, FILE *fp);
void game_loop(t_elem *e, t_res *res, t_button_list *list);
void save(int nb_save, t_elem *e);
void load_suite(char **str, t_elem *e);
void load_color(char **str, t_elem *e);
void load(int nb_save, t_elem *e);
char *all_file(FILE *fp);
t_button_set *init_settings(void);
void check_settings(t_button_set *set, sfMouseMoveEvent button);
void analyse_settings(t_button_set *settings, t_res *res, t_elem *e);
void check_state(t_button_set *settings);
void diplay_settings(t_button_set *settings, t_res *res);
void change_display_set(t_button *data, int act, int posY);
void update_settings(t_button_set *settings, int i, t_elem *e, t_res *res);
void click_scene(t_button_set *set, sfMouseButtonEvent, t_elem *e, t_res *);
int asking_save(void);
void save_set(t_elem *e);
int asking_load(void);
void load_set(t_elem *e);
void around_str(float **str, float around, float smooth, int i, float **tmp);
void average_2(float **str, float **tmp, int k);
void smoother_2(float **str, float **tmp);
float **map_generator(float height_max, float height_min, \
int freq_max, int freq_min);
void bubble_sort(int point[4]);
void check_color(t_elem *e, int i, int highest);
int highest(int p1, int p2, int p3, int p4);
void load_color_save(t_elem *e);
int check_good_load(char *buffer, int n);

#endif /* !MY */