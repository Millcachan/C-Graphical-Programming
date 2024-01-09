/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** simulation
*/

#include "../include/my.h"

static int analyse_events_menu(win_t *win, global *radar)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed) {
            sfRenderWindow_close(win->win);
            return EXIT_SUCCESS;
        }
        if (win->event.key.code == sfKeySpace)
            radar->scene = 1;
    }
    return EXIT_FAILURE;
}

static int analyse_events_simulation(win_t *win, infos_t *info)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed) {
            sfRenderWindow_close(win->win);
            return EXIT_SUCCESS;
        }
        if (win->event.type == sfEvtKeyPressed &&
        win->event.key.code == sfKeyL)
            info->disp_hitbox = 1 - info->disp_hitbox;
        if (win->event.type == sfEvtKeyPressed &&
        win->event.key.code == sfKeyS)
            info->disp_sprites = 1 - info->disp_sprites;
    }
    return EXIT_FAILURE;
}

static int analyse_events_results(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed) {
            sfRenderWindow_close(win->win);
            return EXIT_SUCCESS;
        }
        if (win->event.type == sfEvtKeyPressed &&
        win->event.key.code == sfKeySpace) {
            sfRenderWindow_close(win->win);
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

static int analyse_events(global *radar)
{
    switch (radar->scene) {
        case MENU:
            return analyse_events_menu(&radar->win, radar);
        case SIMULATION:
            return analyse_events_simulation(&radar->win, &radar->infos);
        case RESULTS:
            return analyse_events_results(&radar->win);
    }
    return EXIT_FAILURE;
}

int run_simulation(global *radar)
{
    while (sfRenderWindow_isOpen(radar->win.win)) {
        if (analyse_events(radar) == EXIT_SUCCESS)
            return SUCCESS;
        run_clock(radar->clock, radar);
        disp(radar, radar->scene);
    }
    return SUCCESS;
}
