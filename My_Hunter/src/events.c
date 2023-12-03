/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** events
*/

#include "../include/my.h"

static void destroy_clock(clock_type *clock)
{
    my_putstr("\n>Clock : succefully destroyed\n");
    sfClock_destroy(clock->clock);
}

static void sound(music_t *music)
{
    if (sfSound_getVolume(music->sound_game) != 0.0) {
        sfSound_setVolume(music->sound_menu, 0.0f);
        sfSound_setVolume(music->sound_game, 0.0f);
        sfSound_setVolume(music->sound_over, 0.0f);
    } else {
        sfSound_setVolume(music->sound_menu, 10.0f);
        sfSound_setVolume(music->sound_game, 10.0f);
        sfSound_setVolume(music->sound_over, 10.0f);
    }
}

void if_click_menu(sfMouseButtonEvent event, global_t *global)
{
    if (event.x >= 600 && event.x <= 1315) {
        if (event.y >= 400 && event.y <= 585) {
            my_putstr("\n>Menu sprite : succefully destroyed\n");
            sfSound_stop(global->music.sound_menu);
            sfSprite_destroy(global->menu.start.sprite);
            sfSprite_destroy(global->menu.back.sprite);
            sfSprite_destroy(global->menu.satyr.sprite);
            my_putstr("\n>Game : started\n");
            game(global);
        }
    }
    if (event.x >= 20 && event.x <= 320) {
        if (event.y >= 20 && event.y <= 340) {
            move_rect(&global->menu.sound.rect, 115, 115);
            sfSprite_setTextureRect(global->menu.sound.sprite,
            global->menu.sound.rect);
            sound(&global->music);
        }
    }
}

void if_click_over(sfMouseButtonEvent event, global_t *global)
{
    if (event.x >= 1610 && event.x <= 1810) {
        if (event.y >= 755 && event.y <= 965) {
            sfSound_stop(global->music.sound_over);
            my_putstr("\n>Game : restarted\n");
            init_game(&global->game);
            game(global);
        }
    }
}

static void reset_pos(game_t *game, int sprite)
{
    if (sprite == 1) {
        game->sprite1.pos = (sfVector2f){-300, (rand() % 800) + 50};
        sfSprite_setPosition(game->sprite1.sprite, game->sprite1.pos);
    }
    if (sprite == 2) {
        game->sprite2.pos = (sfVector2f){-300, (rand() % 800) + 50};
        sfSprite_setPosition(game->sprite2.sprite, game->sprite2.pos);
    }
    if (sprite == 3) {
        game->sprite3.pos = (sfVector2f){-300, (rand() % 800) + 50};
        sfSprite_setPosition(game->sprite3.sprite, game->sprite3.pos);
    }
    if (sprite == 4) {
        game->sprite4.pos = (sfVector2f){-300, (rand() % 800) + 50};
        sfSprite_setPosition(game->sprite4.sprite, game->sprite4.pos);
    }
}

static void if_click_game_bis(sfMouseButtonEvent event, game_t *game)
{
    if (event.x >= game->sprite3.pos.x + 40 &&
        event.x <= game->sprite3.pos.x + 152 &&
        event.y >= game->sprite3.pos.y + 20 &&
        event.y <= game->sprite3.pos.y + 172) {
        reset_pos(game, 3);
        game->sprite3.velocity.x += 0.5;
        return;
    }
    if (event.x >= game->sprite4.pos.x + 40 &&
        event.x <= game->sprite4.pos.x + 152 &&
        event.y >= game->sprite4.pos.y + 20 &&
        event.y <= game->sprite4.pos.y + 172) {
        reset_pos(game, 4);
        game->sprite4.velocity.x += 0.5;
        return;
    }
}

static void if_click_game(sfMouseButtonEvent event, game_t *game)
{
    if (event.x >= game->sprite1.pos.x + 40 &&
        event.x <= game->sprite1.pos.x + 152 &&
        event.y >= game->sprite1.pos.y + 20 &&
        event.y <= game->sprite1.pos.y + 172) {
        game->sprite1.velocity.x += 0.5;
        game->score.score_int += 10;
        reset_pos(game, 1);
        return;
    }
    if (event.x >= game->sprite2.pos.x + 40 &&
        event.x <= game->sprite2.pos.x + 152 &&
        event.y >= game->sprite2.pos.y + 20 &&
        event.y <= game->sprite2.pos.y + 172) {
        game->sprite2.velocity.x += 0.5;
        game->score.score_int += 10;
        reset_pos(game, 2);
        return;
    }
    if_click_game_bis(event, game);
}

void analyse_events_over(sfRenderWindow *win, sfEvent event, global_t *global)
{
    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(win);
            destroy_clock(&global->clock);
            destroy_window(global);
            destroy_over(global);
            destroy_music(&global->music);
            destroy_textures(global);
            destroy_text(global);
            free(global->game.score.str);
            exit(0);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if_click_over(event.mouseButton, global);
        }
    }
}

void analyse_events_menu(sfRenderWindow *win, sfEvent event, global_t *global)
{
    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(win);
            destroy_clock(&global->clock);
            destroy_window(global);
            destroy_menu(global);
            destroy_music(&global->music);
            destroy_textures(global);
            destroy_text(global);
            free(global->game.score.str);
            exit(0);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if_click_menu(event.mouseButton, global);
        }
    }
}

void analyse_events_game(sfRenderWindow *win, sfEvent event, global_t *global)
{
    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(win);
            destroy_clock(&global->clock);
            destroy_game(global);
            destroy_music(&global->music);
            destroy_textures(global);
            destroy_window(global);
            destroy_text(global);
            free(global->game.score.str);
            exit(0);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if_click_game(event.mouseButton, &global->game);
        }
    }
}
