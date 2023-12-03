/*
** EPITECH PROJECT, 2023
** test
** File description:
** init
*/

#include "../include/my.h"

static void init_window(win_t *window_s)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow *window = sfRenderWindow_create(mode,
    "Tiny death", sfResize | sfClose, NULL);

    if (!window)
        exit(84);
    window_s->mode = mode;
    window_s->win = window;
    window_s->framerate_limit = 60;
    sfWindow_setFramerateLimit((sfWindow *)window, window_s->framerate_limit);
}

static void init_clock(clock_type *clock_s)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 100000.0;

    clock_s->clock = clock;
    clock_s->time = time;
    clock_s->seconds = seconds;
}

void init_score(score_t *score)
{
    score->font = sfFont_createFromFile("asset/font.TTF");
    score->score_int = 0;
    score->str = malloc(sizeof(char) * 100);
    score->best = read_best_score();
    score->score_pos = (sfVector2f){10, 25};
    score->int_pos = (sfVector2f){520, 25};
    score->best_score_pos = (sfVector2f){10, -20};
    score->best_int_pos = (sfVector2f){650, -20};
    score->score_text = sfText_create();
    score->int_text = sfText_create();
    score->best_score_text = sfText_create();
    score->best_int_text = sfText_create();
    score->size = 75;
}

void init_game(game_t *game)
{
    sfTexture *back = sfTexture_createFromFile("asset/bg.jpg", NULL);

    game->back.sprite = sfSprite_create();
    game->back.texture = back;
    game->back.pos = (sfVector2f){0, -45};
    game->back.scale = (sfVector2f){6.0, 6.0};
    sfSprite_setTexture(game->back.sprite, back, sfTrue);
    srand(time(NULL));
    init_sprite(&game->sprite1);
    init_sprite(&game->sprite2);
    init_sprite(&game->sprite3);
    init_sprite(&game->sprite4);
    init_score(&game->score);
}

static void init_music(music_t *music)
{
    sfSoundBuffer *buf_menu = sfSoundBuffer_createFromFile("asset/menu.ogg");
    sfSoundBuffer *buf_game = sfSoundBuffer_createFromFile("asset/game.ogg");
    sfSoundBuffer *buf_over = sfSoundBuffer_createFromFile("asset/over.ogg");

    music->buf_menu = buf_menu;
    music->buf_game = buf_game;
    music->buf_over = buf_over;
    music->sound_menu = sfSound_create();
    music->sound_game = sfSound_create();
    music->sound_over = sfSound_create();
    sfSound_setBuffer(music->sound_menu, buf_menu);
    sfSound_setBuffer(music->sound_game, buf_game);
    sfSound_setBuffer(music->sound_over, buf_over);
    sfSound_setVolume(music->sound_menu, 10.0f);
    sfSound_setVolume(music->sound_game, 10.0f);
    sfSound_setVolume(music->sound_over, 10.0f);
}

static void init_stand(over_t *over)
{
    sfTexture *stand = sfTexture_createFromFile("asset/stand.png", NULL);
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 32;
    rect.height = 32;
    over->stand1.sprite = sfSprite_create();
    over->stand2.sprite = sfSprite_create();
    over->stand1.texture = stand;
    over->stand1.pos = (sfVector2f){90, 100};
    over->stand2.pos = (sfVector2f){1870, 100};
    over->stand1.scale = (sfVector2f){13.0, 13.0};
    over->stand2.scale = (sfVector2f){-13.0, 13.0};
    over->stand1.rect = rect;
    sfSprite_setTexture(over->stand1.sprite, stand, sfTrue);
    sfSprite_setTexture(over->stand2.sprite, stand, sfTrue);
    sfSprite_setTextureRect(over->stand1.sprite, over->stand1.rect);
    sfSprite_setTextureRect(over->stand1.sprite, over->stand1.rect);
}

void init_over(over_t *over)
{
    sfTexture *back = sfTexture_createFromFile("asset/bg.jpg", NULL);
    sfTexture *restart = sfTexture_createFromFile("asset/re.png", NULL);
    sfTexture *over_texture = sfTexture_createFromFile("asset/over.png", NULL);

    over->back.sprite = sfSprite_create();
    over->over.sprite = sfSprite_create();
    over->restart.sprite = sfSprite_create();
    over->back.texture = back;
    over->over.texture = over_texture;
    over->restart.texture = restart;
    over->back.pos = (sfVector2f){0, -45};
    over->over.pos = (sfVector2f){420, -220};
    over->restart.pos = (sfVector2f){1550, 700};
    over->over.scale = (sfVector2f){1.0, 1.0};
    over->back.scale = (sfVector2f){6.0, 6.0};
    over->restart.scale = (sfVector2f){1.6, 1.6};
    sfSprite_setTexture(over->back.sprite, back, sfTrue);
    sfSprite_setTexture(over->over.sprite, over_texture, sfTrue);
    sfSprite_setTexture(over->restart.sprite, restart, sfTrue);
    init_stand(over);
}

static void init_satyr(menu_t *menu)
{
    sfTexture *satyr = sfTexture_createFromFile("asset/stand.png", NULL);

    menu->satyr.rect.top = 0;
    menu->satyr.rect.left = 0;
    menu->satyr.rect.width = 32;
    menu->satyr.rect.height = 32;
    menu->sound.rect.top = 0;
    menu->sound.rect.left = 0;
    menu->sound.rect.width = 110;
    menu->sound.rect.height = 180;
    menu->satyr.sprite = sfSprite_create();
    menu->satyr.texture = satyr;
    menu->satyr.pos = (sfVector2f){790, 135};
    menu->satyr.scale = (sfVector2f){10.0, 10.0};
    sfSprite_setTexture(menu->satyr.sprite, satyr, sfTrue);
    sfSprite_setTextureRect(menu->satyr.sprite, menu->satyr.rect);
}

static void init_menu(menu_t *menu)
{
    sfTexture *back = sfTexture_createFromFile("asset/menu.jpg", NULL);
    sfTexture *start = sfTexture_createFromFile("asset/start.png", NULL);
    sfTexture *sound = sfTexture_createFromFile("asset/audio.png", NULL);

    menu->back.sprite = sfSprite_create();
    menu->start.sprite = sfSprite_create();
    menu->sound.sprite = sfSprite_create();
    menu->back.texture = back;
    menu->start.texture = start;
    menu->sound.texture = start;
    menu->back.pos = (sfVector2f){0, -45};
    menu->start.pos = (sfVector2f){380, -100};
    menu->sound.pos = (sfVector2f){0, -30};
    menu->back.scale = (sfVector2f){1.0, 0.95};
    menu->start.scale = (sfVector2f){1.0, 1.0};
    menu->sound.scale = (sfVector2f){1.2, 1.2};
    sfSprite_setTexture(menu->back.sprite, back, sfTrue);
    sfSprite_setTexture(menu->start.sprite, start, sfTrue);
    sfSprite_setTexture(menu->sound.sprite, sound, sfTrue);
    init_satyr(menu);
}

void init(global_t *global)
{
    init_window(&global->win);
    init_music(&global->music);
    init_menu(&global->menu);
    init_game(&global->game);
    init_clock(&global->clock);
    init_over(&global->over);
}
