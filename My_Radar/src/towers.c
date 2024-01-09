/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** towers
*/

#include "../include/my.h"

static void set_tower(tower *new_tower, textures_t *textures)
{
    sfCircleShape_setPosition(new_tower->hitbox, (sfVector2f){new_tower->pos.x
    - new_tower->radius + 20, new_tower->pos.y - new_tower->radius + 20});
    sfSprite_setTexture(new_tower->sprite, textures->tower, sfTrue);
    sfSprite_setPosition(new_tower->sprite, new_tower->pos);
}

static tower *create_new_tower(char *infos, textures_t *textures)
{
    char **split_infos = my_str_to_word_array(infos);
    tower *new_tower = malloc((size_t)(sizeof(tower)));

    new_tower->pos.x = (float)my_getnbr(split_infos[1]);
    new_tower->pos.y = (float)my_getnbr(split_infos[2]);
    new_tower->radius = (float)(1920.0 *
    ((double)my_getnbr(split_infos[3]) / 200.0));
    new_tower->sprite = sfSprite_create();
    new_tower->hitbox = create_circle(new_tower->pos, new_tower->radius);
    new_tower->center = (sfVector2f){new_tower->pos.x + 20,
    new_tower->pos.y + 20};
    set_tower(new_tower, textures);
    for (int i = 0; split_infos[i]; i++)
        free(split_infos[i]);
    free(split_infos);
    return new_tower;
}

tower *add_tower(tower **head, char *infos, textures_t *textures)
{
    tower *new_tower = create_new_tower(infos, textures);

    new_tower->next = *head;
    return new_tower;
}
