/*
** EPITECH PROJECT, 2023
** test
** File description:
** menu
*/

#include "../include/my.h"

void destroy_window(global_t *global)
{
    my_putstr("\n>Window : successfully destroyed\n");
    sfRenderWindow_destroy(global->win.win);
}

static void set_sprites_menu(menu_t *menu)
{
    my_putstr("\n>Menu sprites : successfully set\n");
    sfSprite_setScale(menu->back.sprite, menu->back.scale);
    sfSprite_setPosition(menu->back.sprite, menu->back.pos);
    sfSprite_setScale(menu->start.sprite, menu->start.scale);
    sfSprite_setPosition(menu->start.sprite, menu->start.pos);
    sfSprite_setScale(menu->satyr.sprite, menu->satyr.scale);
    sfSprite_setPosition(menu->satyr.sprite, menu->satyr.pos);
    sfSprite_setScale(menu->sound.sprite, menu->sound.scale);
    sfSprite_setPosition(menu->sound.sprite, menu->sound.pos);
    sfSprite_setTextureRect(menu->sound.sprite, menu->sound.rect);
}

static void display_menu(win_t *win, menu_t *menu)
{
    sfRenderWindow_clear(win->win, sfRed);
    sfRenderWindow_drawSprite(win->win, menu->back.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, menu->start.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, menu->satyr.sprite, NULL);
    sfRenderWindow_drawSprite(win->win, menu->sound.sprite, NULL);
    sfRenderWindow_display(win->win);
}

void destroy_menu(global_t *global)
{
    my_putstr("\n>Menu sprites : successfully destroyed\n");
    sfSprite_destroy(global->menu.satyr.sprite);
    sfSprite_destroy(global->menu.start.sprite);
    sfSprite_destroy(global->menu.back.sprite);
    sfSprite_destroy(global->menu.sound.sprite);
}

static void clock_menu(clock_type clock, global_t *global)
{
    clock.time = sfClock_getElapsedTime(clock.clock);
    clock.seconds = clock.time.microseconds / 1000000.0;
    if (clock.seconds > 0.1) {
        sfClock_restart(clock.clock);
        sfSprite_setTextureRect(global->menu.satyr.sprite,
        global->menu.satyr.rect);
        move_rect(&global->menu.satyr.rect, 32, 128);
    }
}

int menu(global_t *global)
{
    set_sprites_menu(&global->menu);
    my_putstr("\n>Playing : Undertale - Menu\n");
    sfSound_play(global->music.sound_menu);
    while (sfRenderWindow_isOpen(global->win.win)) {
        if (sfSound_getStatus(global->music.sound_menu) != sfPlaying)
            sfSound_play(global->music.sound_menu);
        clock_menu(global->clock, global);
        analyse_events_menu(global->win.win, global->win.event, global);
        display_menu(&global->win, &global->menu);
    }
    return 0;
}
