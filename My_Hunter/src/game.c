/*
** EPITECH PROJECT, 2023
** test
** File description:
** game
*/

#include "../include/my.h"

static void set_sprites_game(game_t *game)
{
    my_putstr("\n>Game sprites : successfully set\n");
    sfSprite_setScale(game->back.sprite, game->back.scale);
    sfSprite_setScale(game->sprite1.sprite, game->sprite1.scale);
    sfSprite_setScale(game->sprite2.sprite, game->sprite2.scale);
    sfSprite_setScale(game->sprite3.sprite, game->sprite3.scale);
    sfSprite_setScale(game->sprite4.sprite, game->sprite4.scale);
    sfSprite_setPosition(game->back.sprite, game->back.pos);
    sfSprite_setPosition(game->sprite1.sprite, game->sprite1.pos);
    sfSprite_setPosition(game->sprite2.sprite, game->sprite2.pos);
    sfSprite_setPosition(game->sprite3.sprite, game->sprite3.pos);
    sfSprite_setPosition(game->sprite4.sprite, game->sprite4.pos);
    set_score(&game->score);
}

static void display_game(win_t *win, game_t *game)
{
    sfRenderWindow_clear(win->win, sfRed);
    sfRenderWindow_drawSprite(win->win, game->back.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, game->sprite1.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, game->sprite2.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, game->sprite3.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, game->sprite4.sprite, NULL);
    sfRenderWindow_drawText(win->win, game->score.score_text, NULL);
    sfRenderWindow_drawText(win->win, game->score.int_text, NULL);
    sfRenderWindow_drawText(win->win, game->score.best_score_text, NULL);
    sfRenderWindow_drawText(win->win, game->score.best_int_text, NULL);
    sfRenderWindow_display(win->win);
}

static void sprite_rect(game_t *game)
{
    sfSprite_setTextureRect(game->sprite1.sprite, game->sprite1.rect);
    sfSprite_setTextureRect(game->sprite2.sprite, game->sprite2.rect);
    sfSprite_setTextureRect(game->sprite3.sprite, game->sprite3.rect);
    sfSprite_setTextureRect(game->sprite4.sprite, game->sprite4.rect);
    move_rect(&game->sprite1.rect, 32, 192);
    move_rect(&game->sprite2.rect, 32, 192);
    move_rect(&game->sprite3.rect, 32, 192);
    move_rect(&game->sprite4.rect, 32, 192);
}

static void reset_pos(game_t *game)
{
    sfSprite_setPosition(game->sprite1.sprite, game->sprite1.pos);
    sfSprite_setPosition(game->sprite2.sprite, game->sprite2.pos);
    sfSprite_setPosition(game->sprite3.sprite, game->sprite3.pos);
    sfSprite_setPosition(game->sprite4.sprite, game->sprite4.pos);
}

void destroy_game(global_t *global)
{
    my_putstr("\n>Game sprites : successfully destroyed\n");
    sfSprite_destroy(global->game.back.sprite);
    sfSprite_destroy(global->game.sprite1.sprite);
    sfSprite_destroy(global->game.sprite2.sprite);
    sfSprite_destroy(global->game.sprite3.sprite);
    sfSprite_destroy(global->game.sprite4.sprite);
}

static void actualize_text(score_t *score)
{
    if (score->score_int > score->best)
        score->best = score->score_int;
    sfText_setString(score->int_text, to_str(score->score_int, score->str));
    sfText_setString(score->best_int_text, to_str(score->best, score->str));
}

static void clock_game(clock_type clock, global_t *global)
{
    clock.time = sfClock_getElapsedTime(clock.clock);
    clock.seconds = clock.time.microseconds / 1000000.0;
    if (clock.seconds > 0.05) {
        global->game.score.score_int += 1;
        sfClock_restart(clock.clock);
        reset_pos(&global->game);
        sprite_rect(&global->game);
        run(&global->game);
    }
}

int game(global_t *global)
{
    set_sprites_game(&global->game);
    sprite_rect(&global->game);
    my_putstr("\n>Clock : started\n");
    my_putstr("\n>Playing : Undertale - Wrong Enemy\n");
    sfSound_play(global->music.sound_game);
    sfRenderWindow_clear(global->win.win, sfRed);
    while (sfRenderWindow_isOpen(global->win.win)) {
        if (sfSound_getStatus(global->music.sound_game) != sfPlaying)
            sfSound_play(global->music.sound_game);
        actualize_text(&global->game.score);
        clock_game(global->clock, global);
        analyse_events_game(global->win.win, global->win.event, global);
        is_gameover(global, &global->game);
        display_game(&global->win, &global->game);
    }
    return 0;
}
