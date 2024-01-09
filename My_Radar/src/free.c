/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** free
*/

#include "../include/my.h"

static void destroy_planes(infos_t *infos)
{
    plane *temp = NULL;

    while (infos->head_plane) {
        temp = infos->head_plane->next;
        sfSprite_destroy(infos->head_plane->sprite);
        sfRectangleShape_destroy(infos->head_plane->hitbox);
        free(infos->head_plane);
        infos->head_plane = temp;
    }
}

static void destroy_towers(infos_t *infos)
{
    tower *temp = NULL;

    while (infos->head_tower) {
        temp = infos->head_tower->next;
        sfSprite_destroy(infos->head_tower->sprite);
        sfCircleShape_destroy(infos->head_tower->hitbox);
        free(infos->head_tower);
        infos->head_tower = temp;
    }
}

static void text_destroy(global *radar)
{
    sfText_destroy(radar->text.seconds_text);
    sfText_destroy(radar->text.timer_text);
    sfText_destroy(radar->text.start_text);
    sfText_destroy(radar->text.result_text);
    free(radar->text.seconds_string);
}

static void texture_destroy(global *radar)
{
    sfTexture_destroy(radar->background.texture);
    sfTexture_destroy(radar->textures.plane);
    sfTexture_destroy(radar->textures.tower);
    sfTexture_destroy(radar->textures.explo);
    sfTexture_destroy(radar->textures.flag);
}

static void destroy(global *radar)
{
    sfRenderWindow_destroy(radar->win.win);
    sfClock_destroy(radar->clock.clock);
    texture_destroy(radar);
    sfSprite_destroy(radar->background.sprite);
    destroy_planes(&radar->infos);
    destroy_towers(&radar->infos);
    text_destroy(radar);
    sfFont_destroy(radar->text.font);
}

int free_simulation(global *radar)
{
    for (int i = 0; radar->infos.script[i]; i++)
        free(radar->infos.script[i]);
    free(radar->infos.script);
    destroy(radar);
    return SUCCESS;
}
