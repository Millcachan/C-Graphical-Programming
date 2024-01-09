/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** colisions
*/

#include "../include/my.h"

static void run_planes(plane *current, global *radar)
{
    if (!current->flying && (radar->text.seconds_int / 20 >= current->delay))
        current->flying = true;
    if (current->flying && !current->arrived && current->alive) {
        current->pos.x += (float)current->offset_x;
        current->pos.y += (float)current->offset_y;
    }
    sfSprite_setPosition(current->sprite, current->pos);
    sfRectangleShape_setPosition(current->hitbox, current->pos);
}

static void is_arrived(plane *current, global *radar)
{
    if (current->pos.x <= current->end.x + 10 &&
        current->pos.x >= current->end.x - 10 &&
        current->pos.y <= current->end.y + 10 &&
        current->pos.y >= current->end.y - 10) {
        current->arrived = true;
        sfSprite_setTexture(current->sprite, radar->textures.flag, sfTrue);
        sfSprite_setRotation(current->sprite, 0);
    }
}

static int point_in_cercle(float xp, float yp, sfVector2f circle, float radius)
{
    return ((((xp - circle.x) * (xp - circle.x)) +
    ((yp - circle.y) * (yp - circle.y))) < (radius * radius));
}

static int is_protected(plane *cp, global *radar)
{
    tower *ct = radar->infos.head_tower;

    while (ct) {
        if (point_in_cercle(cp->pos.x - 10, cp->pos.y - 10,
            ct->center, ct->radius))
            return true;
        if (point_in_cercle(cp->pos.x + 10, cp->pos.y - 10,
            ct->center, ct->radius))
            return true;
        if (point_in_cercle(cp->pos.x - 10, cp->pos.y + 10,
            ct->center, ct->radius))
            return true;
        if (point_in_cercle(cp->pos.x + 10, cp->pos.y + 10,
            ct->center, ct->radius))
            return true;
        ct = ct->next;
    }
    return false;
}

static void planes(global *radar)
{
    plane *current = radar->infos.head_plane;

    while (current) {
        if (!current->alive || current->arrived)
            current->hide = current->hide + 1;
        run_planes(current, radar);
        is_arrived(current, radar);
        if (is_protected(current, radar))
            current->protected = true;
        else
            current->protected = false;
        current = current->next;
    }
}

static int is_finished(infos_t *info)
{
    plane *current = info->head_plane;

    while (current) {
        if (current->hide < 10)
            return false;
        current = current->next;
    }
    return true;
}

void simulation(global *radar)
{
    planes(radar);
    collisions(&radar->infos, &radar->textures);
    if (is_finished(&radar->infos))
        radar->scene = RESULTS;
}
