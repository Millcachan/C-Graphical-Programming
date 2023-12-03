/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

#ifndef MY_H_
    #define MY_H_

typedef struct sprite_s {
    sfVector2f velocity;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
} sprite_t;

typedef struct over_s {
    sprite_t restart;
    sprite_t back;
    sprite_t over;
    sprite_t stand1;
    sprite_t stand2;
} over_t;

typedef struct win_s {
    sfRenderWindow *win;
    int framerate_limit;
    sfVideoMode mode;
    sfEvent event;
} win_t;

typedef struct menu_s {
    sprite_t start;
    sprite_t satyr;
    sprite_t back;
    sprite_t sound;
} menu_t;

typedef struct score_s {
    sfVector2f best_score_pos;
    sfVector2f best_int_pos;
    long long int score_int;
    sfText *best_score_text;
    sfText *best_int_text;
    sfVector2f score_pos;
    long long int best;
    sfVector2f int_pos;
    sfText *score_text;
    sfText *int_text;
    sfFont *font;
    char *str;
    int size;
} score_t;

typedef struct game_s {
    sprite_t sprite1;
    sprite_t sprite2;
    sprite_t sprite3;
    sprite_t sprite4;
    sprite_t back;
    score_t score;
} game_t;

typedef struct clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} clock_type;

typedef struct music_s {
    sfSoundBuffer *buf_menu;
    sfSoundBuffer *buf_game;
    sfSoundBuffer *buf_over;
    sfSound *sound_menu;
    sfSound *sound_game;
    sfSound *sound_over;
} music_t;

typedef struct global_s {
    clock_type clock;
    music_t music;
    menu_t menu;
    game_t game;
    over_t over;
    win_t win;
} global_t;

void run(game_t *game);
int my_strlen(char *str);
int my_putstr(char *str);
int read_best_score(void);
int menu(global_t *global);
int game(global_t *global);
void init(global_t *global);
void init_over(over_t *over);
void init_game(game_t *game);
void set_score(score_t *score);
void new_best_score(game_t *game);
void init_sprite(sprite_t *sprite);
void destroy_music(music_t *music);
void init_sprite(sprite_t *sprite);
void destroy_text(global_t *global);
void destroy_game(global_t *global);
void destroy_menu(global_t *global);
void destroy_over(global_t *global);
char *to_str(long long nb, char *str);
void destroy_window(global_t *global);
void destroy_textures(global_t *global);
int my_strcmp(char const *s1, char const *s2);
void is_gameover(global_t *global, game_t *game);
void move_rect(sfIntRect *rect, int offset, int max_value);
void if_click_menu(sfMouseButtonEvent event, global_t *global);
void if_click_over(sfMouseButtonEvent event, global_t *global);
void analyse_events_game(sfRenderWindow *win, sfEvent event, global_t *global);
void analyse_events_menu(sfRenderWindow *win, sfEvent event, global_t *global);
void analyse_events_over(sfRenderWindow *win, sfEvent event, global_t *global);

#endif
