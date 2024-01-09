/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** hitbox
*/

#include "../include/my.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfBlack);
    sfCircleShape_setFillColor(circle, sfTransparent);
    return circle;
}

sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRectangleShape_setOutlineColor(rectangle, sfBlack);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    return rectangle;
}
