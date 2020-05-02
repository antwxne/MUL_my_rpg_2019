/*
** EPITECH PROJECT, 2020
** 42
** File description:
** 42
*/

#include "particule.h"

void make_rain(part_t *part, color_t color)
{
    int pos_x = 0;

    while (part != NULL) {
        part->speed = 1;
        part->size = (sfVector2f) {2, 5};
        part->direction = (sfVector2f) {0, (rand() % 100)};
        sfRectangleShape_setPosition(part->shape, (sfVector2f) {pos_x, 0});
        sfRectangleShape_setOutlineThickness(part->shape, 1);
        sfRectangleShape_scale(part->shape, (sfVector2f) {0.25, 0.25});
        pos_x = pos_x + 20;
        part = part->next;
    }
}

void rain(part_t *part, game_t *game, color_t color)
{
    sfVector2f pos;
    static int n;

    if (n == 0)
        make_rain(part, color);
    while (part != NULL) {
        pos = sfRectangleShape_getPosition(part->shape);
        pos.x = pos.x + (part->speed * part->direction.x);
        pos.y = pos.y + (part->speed * part->direction.y);
        sfRectangleShape_setPosition(part->shape, pos);
        sfRectangleShape_setOutlineColor(part->shape, color.coloring);
        sfRectangleShape_setFillColor(part->shape, color.color_fill);
        if (pos.y >= 1080 || pos.y <= 0)
            sfRectangleShape_setPosition(part->shape, (sfVector2f) {pos.x, 0});
        else if (part->lifetime == 1)
            sfRenderWindow_drawRectangleShape(game->window, part->shape, NULL);
        part = part->next;
    }
    n++;
}