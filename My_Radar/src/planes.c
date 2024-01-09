/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** planes
*/

#include "../include/my.h"

static void compute_speed(plane *new_plane)
{
    double delta_x = new_plane->end.x - new_plane->start.x;
    double delta_y = new_plane->end.y - new_plane->start.y;
    double angle = atan2(delta_y, delta_x);

    new_plane->offset_x = new_plane->speed * cos(angle) * 0.10;
    new_plane->offset_y = new_plane->speed * sin(angle) * 0.10;
    sfSprite_setRotation(new_plane->sprite,
    (float)(angle * (180 / 3.1415) + 90));
}

static void set_plane(plane *new_plane, textures_t *textures)
{
    new_plane->alive = true;
    new_plane->flying = false;
    new_plane->arrived = false;
    new_plane->protected = false;
    new_plane->hide = 0;
    new_plane->hitbox = create_rectangle(new_plane->pos, (sfVector2f){20, 20});
    new_plane->sprite = sfSprite_create();
    sfSprite_setOrigin(new_plane->sprite, (sfVector2f){10, 10});
    sfRectangleShape_setOrigin(new_plane->hitbox, (sfVector2f){10, 10});
    sfSprite_setTexture(new_plane->sprite, textures->plane, sfTrue);
    sfSprite_setPosition(new_plane->sprite, new_plane->start);
}

static plane *create_new_plane(char *infos, textures_t *textures)
{
    char **split_infos = my_str_to_word_array(infos);
    plane *new_plane = malloc((size_t)(sizeof(plane)));

    new_plane->start.x = (float)my_getnbr(split_infos[1]);
    new_plane->start.y = (float)my_getnbr(split_infos[2]);
    new_plane->end.x = (float)my_getnbr(split_infos[3]);
    new_plane->end.y = (float)my_getnbr(split_infos[4]);
    new_plane->speed = (int)my_getnbr(split_infos[5]);
    new_plane->delay = (int)my_getnbr(split_infos[6]);
    new_plane->pos = new_plane->start;
    set_plane(new_plane, textures);
    compute_speed(new_plane);
    for (int i = 0; split_infos[i]; i++)
        free(split_infos[i]);
    free(split_infos);
    return new_plane;
}

plane *add_plane(plane **head, char *infos, textures_t *textures)
{
    plane *new_plane = create_new_plane(infos, textures);

    new_plane->next = *head;
    return new_plane;
}
