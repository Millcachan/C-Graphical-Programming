/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** collisions
*/

#include "../include/my.h"

static int is_crashed(plane *a, plane *b)
{
    return (a->pos.x - 10 <= b->pos.x + 10 &&
            a->pos.x + 10 >= b->pos.x - 10 &&
            a->pos.y - 10 <= b->pos.y + 10 &&
            a->pos.y + 10 >= b->pos.y - 10);
}

static void collision(plane *to_compare, textures_t *textures)
{
    plane *current = to_compare->next;

    if (!to_compare->alive || !to_compare->flying)
        return;
    while (current) {
        if (((!current->protected && !current->arrived && current->alive) &&
        (!to_compare->protected && !to_compare->arrived && to_compare->alive))
        && (to_compare->flying && current->flying) &&
        is_crashed(to_compare, current)) {
            to_compare->alive = false;
            current->alive = false;
            sfSprite_setTexture(to_compare->sprite, textures->explo, sfTrue);
            sfSprite_setTexture(current->sprite, textures->explo, sfTrue);
            return;
        }
        current = current->next;
    }
}

void collisions(infos_t *info, textures_t *textures)
{
    plane *current = info->head_plane;

    while (current) {
        collision(current, textures);
        current = current->next;
    }
}
