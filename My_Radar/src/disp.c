/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** disp
*/

#include "../include/my.h"

static void disp_towers(global *radar)
{
    tower *current = radar->infos.head_tower;

    while (current) {
        if (radar->infos.disp_sprites)
            sfRenderWindow_drawSprite(radar->win.win, current->sprite, NULL);
        if (radar->infos.disp_hitbox)
            sfRenderWindow_drawCircleShape(radar->win.win,
            current->hitbox, NULL);
        current = current->next;
    }
}

static void disp_planes(global *radar)
{
    plane *current = radar->infos.head_plane;

    while (current) {
        if (current->flying && radar->infos.disp_sprites && current->hide < 10)
            sfRenderWindow_drawSprite(radar->win.win, current->sprite, NULL);
        if (current->protected)
            sfRectangleShape_setOutlineColor(current->hitbox, sfGreen);
        else
            sfRectangleShape_setOutlineColor(current->hitbox, sfRed);
        if (current->flying && radar->infos.disp_hitbox && current->hide < 10)
            sfRenderWindow_drawRectangleShape(radar->win.win,
            current->hitbox, NULL);
        current = current->next;
    }
}

static void disp_menu(global *radar)
{
    sfRenderWindow_drawSprite(radar->win.win, radar->background.sprite, NULL);
    sfRenderWindow_drawText(radar->win.win, radar->text.start_text, NULL);
}

static void disp_simulation(global *radar)
{
    sfText_setString(radar->text.seconds_text,
    to_str(radar->text.seconds_int / 20, radar->text.seconds_string));
    sfRenderWindow_drawSprite(radar->win.win, radar->background.sprite, NULL);
    disp_towers(radar);
    disp_planes(radar);
    sfRenderWindow_drawText(radar->win.win, radar->text.timer_text, NULL);
    sfRenderWindow_drawText(radar->win.win, radar->text.seconds_text, NULL);
}

static void disp_results(global *radar)
{
    sfRenderWindow_drawSprite(radar->win.win, radar->background.sprite, NULL);
    sfRenderWindow_drawText(radar->win.win, radar->text.result_text, NULL);
}

void disp(global *radar, state scene)
{
    sfRenderWindow_clear(radar->win.win, sfWhite);
    switch (scene) {
        case MENU:
            disp_menu(radar);
            break;
        case SIMULATION:
            disp_simulation(radar);
            break;
        case RESULTS:
            disp_results(radar);
    }
    sfRenderWindow_display(radar->win.win);
}
