/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** rect_shape
*/

#include "game.h"
#include "rect_shape.h"

sfRectangleShape *create_rect_shape(sfVector2f const info[],
    float const thickness, sfColor const colors[])
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setOrigin(shape, (sfVector2f) {0, 0});
    sfRectangleShape_setPosition(shape, info[POS]);
    sfRectangleShape_setSize(shape, info[SIZE]);
    sfRectangleShape_setOutlineColor(shape, colors[OUTLINE]);
    sfRectangleShape_setFillColor(shape, colors[FILL]);
    sfRectangleShape_setOutlineThickness(shape, thickness);
    return (shape);
}