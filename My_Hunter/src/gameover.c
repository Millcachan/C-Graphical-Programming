/*
** EPITECH PROJECT, 2023
** test
** File description:
** game over
*/

#include "../include/my.h"

static void set_score_over(score_t *score)
{
    sfText_setPosition(score->score_text, (sfVector2f){10, 620});
    sfText_setPosition(score->int_text, (sfVector2f){10, 700});
    sfText_setPosition(score->best_score_text, (sfVector2f){10, 810});
    sfText_setPosition(score->best_int_text, (sfVector2f){10, 890});
    sfText_setCharacterSize(score->best_score_text, 120);
    sfText_setCharacterSize(score->best_int_text, 120);
    sfText_setCharacterSize(score->score_text, 120);
    sfText_setCharacterSize(score->int_text, 120);
}

static void set_sprites_over(over_t *over, score_t *score)
{
    my_putstr("\n>Game over : sprites successfully set\n");
    sfSprite_setScale(over->back.sprite, over->back.scale);
    sfSprite_setPosition(over->back.sprite, over->back.pos);
    sfSprite_setScale(over->over.sprite, over->over.scale);
    sfSprite_setPosition(over->over.sprite, over->over.pos);
    sfSprite_setScale(over->restart.sprite, over->restart.scale);
    sfSprite_setPosition(over->restart.sprite, over->restart.pos);
    sfSprite_setScale(over->stand1.sprite, over->stand1.scale);
    sfSprite_setPosition(over->stand1.sprite, over->stand1.pos);
    sfSprite_setScale(over->stand2.sprite, over->stand2.scale);
    sfSprite_setPosition(over->stand2.sprite, over->stand2.pos);
    set_score_over(score);
}

static void display_over(win_t *win, over_t *over, score_t *score)
{
    sfRenderWindow_clear(win->win, sfRed);
    sfRenderWindow_drawSprite(win->win, over->back.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, over->over.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, over->restart.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, over->stand1.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, over->stand2.sprite, NULL);
    sfRenderWindow_drawText(win->win, score->score_text, NULL);
    sfRenderWindow_drawText(win->win, score->int_text, NULL);
    sfRenderWindow_drawText(win->win, score->best_score_text, NULL);
    sfRenderWindow_drawText(win->win, score->best_int_text, NULL);
    sfRenderWindow_display(win->win);
}

void destroy_over(global_t *global)
{
    my_putstr("\n>Game over : sprites successfully destroyed\n");
    sfSprite_destroy(global->over.back.sprite);
    sfSprite_destroy(global->over.over.sprite);
    sfSprite_destroy(global->over.restart.sprite);
    sfSprite_destroy(global->over.stand1.sprite);
    sfSprite_destroy(global->over.stand2.sprite);
}

static void clock_over(clock_type clock, global_t *global)
{
    clock.time = sfClock_getElapsedTime(clock.clock);
    clock.seconds = clock.time.microseconds / 1000000.0;
    if (clock.seconds > 0.1) {
        sfClock_restart(clock.clock);
        sfSprite_setTextureRect(global->over.stand1.sprite,
        global->over.stand1.rect);
        sfSprite_setTextureRect(global->over.stand2.sprite,
        global->over.stand1.rect);
        move_rect(&global->over.stand1.rect, 32, 128);
    }
}

void gameover(global_t *global)
{
    set_sprites_over(&global->over, &global->game.score);
    sfSprite_setTextureRect(global->over.stand1.sprite,
    global->over.stand1.rect);
    sfSprite_setTextureRect(global->over.stand2.sprite,
    global->over.stand1.rect);
    move_rect(&global->over.stand1.rect, 32, 128);
    my_putstr("\n>Playing : Undertale - Dont't Give Up\n");
    sfSound_play(global->music.sound_over);
    while (sfRenderWindow_isOpen(global->win.win)) {
        if (sfSound_getStatus(global->music.sound_over) != sfPlaying)
            sfSound_play(global->music.sound_over);
        clock_over(global->clock, global);
        analyse_events_over(global->win.win, global->win.event, global);
        display_over(&global->win, &global->over, &global->game.score);
    }
    destroy_over(global);
    destroy_window(global);
}

void is_gameover(global_t *global, game_t *game)
{
    if (game->sprite1.pos.x > 2100 || game->sprite2.pos.x > 2100
    || game->sprite3.pos.x > 2100 || game->sprite4.pos.x > 2100) {
        my_putstr("\n>Menu sprite : succefully destroyed\n");
        if (game->score.best < game->score.score_int)
            new_best_score(game);
        destroy_game(global);
        my_putstr("\n>Game : over screen\n");
        sfSound_stop(global->music.sound_game);
        gameover(global);
    }
}
