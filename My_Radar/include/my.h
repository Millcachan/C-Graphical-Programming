/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#ifndef MY_H_
    #define MY_H_

    #define SUCCESS 0
    #define ERROR 84
    #define HELP 42

typedef enum simulation_state {
    MENU,
    SIMULATION,
    RESULTS
} state;

typedef struct sprite_s {
    sfVector2f velocity;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
} sprite_t;

typedef struct planes_stats {
    struct planes_stats *next;
    sfRectangleShape *hitbox;
    sfVector2f hitbox_pos;
    sfSprite *sprite;
    sfVector2f start;
    double offset_x;
    double offset_y;
    sfVector2f end;
    sfVector2f pos;
    bool protected;
    bool arrived;
    bool flying;
    bool alive;
    int hide;
    int delay;
    int speed;
    int ID;
} plane;

typedef struct towers_stats {
    struct towers_stats *next;
    sfCircleShape *hitbox;
    sfVector2f center;
    sfSprite *sprite;
    sfVector2f pos;
    float radius;
} tower;

typedef struct infos_s {
    plane *head_plane;
    tower *head_tower;
    bool disp_sprites;
    bool disp_hitbox;
    char **script;
} infos_t;

typedef struct win_s {
    sfRenderWindow *win;
    sfVideoMode mode;
    sfEvent event;
    int fl;
} win_t;

typedef struct clock_s {
    sfClock *clock;
    double seconds;
    sfTime time;
} clock_type;

typedef struct textures_s {
    sfTexture *plane;
    sfTexture *tower;
    sfTexture *explo;
    sfTexture *flag;
} textures_t;

typedef struct text_s {
    char *seconds_string;
    sfText *seconds_text;
    sfText *result_text;
    sfText *timer_text;
    sfText *start_text;
    int seconds_int;
    sfFont *font;
} text;

typedef struct global_s {
    sprite_t background;
    textures_t textures;
    clock_type clock;
    infos_t infos;
    state scene;
    text text;
    win_t win;
} global;

int my_strlen(char *str);
char *my_strdup(char *src);
int nb_lines(char *filepath);
long long my_getnbr(char *str);
void simulation(global *radar);
void my_putchar(char c, int fd);
char *to_str(int nb, char *str);
int my_putstr(char *str, int fd);
int usage(int argc, char **argv);
int run_simulation(global *radar);
int my_strcmp(char *s1, char *s2);
int free_simulation(global *radar);
void disp(global *radar, state scene);
void my_putnbr(long long nbr, int fd);
char **my_str_to_word_array(char const *str);
void run_clock(clock_type clock, global *radar);
char **read_script(char *filepath, char **script);
int init_simulation(global *radar, char *filepath);
void collisions(infos_t *info, textures_t *textures);
sfCircleShape *create_circle(sfVector2f position, float radius);
tower *add_tower(tower **head, char *infos, textures_t *textures);
plane *add_plane(plane **head, char *infos, textures_t *textures);
sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size);

#endif
