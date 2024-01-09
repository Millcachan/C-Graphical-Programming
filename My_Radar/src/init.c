/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** parse
*/

#include "../include/my.h"

static void init_planes_towers(infos_t *info, textures_t *textures)
{
    plane *plane_list = NULL;
    tower *tower_list = NULL;

    for (int i = 0; info->script[i]; i++) {
        if (info->script[i][0] == 'A') {
            plane_list = add_plane(&plane_list, info->script[i], textures);
            continue;
        }
        tower_list = add_tower(&tower_list, info->script[i], textures);
    }
    info->head_plane = plane_list;
    info->head_tower = tower_list;
}

static void init_background(sprite_t *background)
{
    sfTexture *back = sfTexture_createFromFile("asset/map.png", NULL);

    background->sprite = sfSprite_create();
    background->texture = back;
    background->pos = (sfVector2f){0, 0};
    background->scale = (sfVector2f){1, (float)0.94};
    sfSprite_setTexture(background->sprite, back, sfTrue);
    sfSprite_setScale(background->sprite, background->scale);
    sfSprite_setPosition(background->sprite, background->pos);
}

static int init_window(win_t *window_s)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow *window = sfRenderWindow_create(mode,
    "My Radar", sfResize | sfClose, NULL);

    if (!window)
        return ERROR;
    window_s->mode = mode;
    window_s->win = window;
    window_s->fl = 60;
    sfWindow_setFramerateLimit((sfWindow *)window, 60);
    return SUCCESS;
}

static void init_clock(clock_type *clock_s)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    double seconds = (double)time.microseconds / 100000.0;

    clock_s->clock = clock;
    clock_s->time = time;
    clock_s->seconds = seconds;
}

static void init_textures(textures_t *textures)
{
    textures->explo = sfTexture_createFromFile("asset/explo.png", NULL);
    textures->plane = sfTexture_createFromFile("asset/plane.png", NULL);
    textures->tower = sfTexture_createFromFile("asset/tower.png", NULL);
    textures->flag = sfTexture_createFromFile("asset/flag.png", NULL);
}

static void init_results(text *text)
{
    text->result_text = sfText_create();
    sfText_setFont(text->result_text, text->font);
    sfText_setString(text->result_text, "Press \"Space\" to quit simulation");
    sfText_setPosition(text->result_text, (sfVector2f){420, 430});
    sfText_setColor(text->result_text, sfBlack);
    sfText_setCharacterSize(text->result_text, 65);
}

static void init_text(text *text)
{
    text->font = sfFont_createFromFile("asset/font.ttf");
    text->start_text = sfText_create();
    text->timer_text = sfText_create();
    text->seconds_text = sfText_create();
    text->seconds_int = 0;
    text->seconds_string = malloc(sizeof(char *));
    sfText_setFont(text->start_text, text->font);
    sfText_setFont(text->timer_text, text->font);
    sfText_setFont(text->seconds_text, text->font);
    sfText_setString(text->start_text, "Press \"Space\" to start simulation");
    sfText_setString(text->timer_text, "Timer:");
    sfText_setPosition(text->start_text, (sfVector2f){400, 430});
    sfText_setPosition(text->timer_text, (sfVector2f){1690, 0});
    sfText_setPosition(text->seconds_text, (sfVector2f){1820, 0});
    sfText_setColor(text->start_text, sfBlack);
    sfText_setColor(text->timer_text, sfBlack);
    sfText_setColor(text->seconds_text, sfBlack);
    sfText_setCharacterSize(text->start_text, 65);
    sfText_setCharacterSize(text->timer_text, 35);
    sfText_setCharacterSize(text->seconds_text, 35);
}

void init(global *radar)
{
    init_textures(&radar->textures);
    init_window(&radar->win);
    init_clock(&radar->clock);
    init_background(&radar->background);
    init_planes_towers(&radar->infos, &radar->textures);
    init_text(&radar->text);
    init_results(&radar->text);
}

int init_simulation(global *radar, char *filepath)
{
    char **script = malloc((size_t)((int)sizeof(char *) * nb_lines(filepath)));

    radar->scene = 0;
    radar->infos.disp_hitbox = true;
    radar->infos.disp_sprites = true;
    radar->infos.script = read_script(filepath, script);
    init(radar);
    return SUCCESS;
}
