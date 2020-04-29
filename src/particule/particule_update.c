/*
** EPITECH PROJECT, 2020
** 42
** File description:
** 42
*/

#include "particule.h"

static const sfVector2f sizes[] = {{20, 30}
};

sfVector2f random_vector(void)
{
    sfVector2f vector;

    vector.x = (rand() % (300 - (-300) + 1) -300);
    vector.y = (rand() % (300 - (-300) + 1) -300);
    return (vector);
}

void update_part(part_t *part, game_t *game)
{
    sfVector2f pos;

    while (part != NULL) {
        pos = sfRectangleShape_getPosition(part->shape);
        pos.x = pos.x + (part->speed * part->direction.x);
        pos.y = pos.y + (part->speed * part->direction.y);
        sfRectangleShape_setPosition(part->shape, pos);
        if (pos.x >= 1920 || pos.y >= 1080 || pos.x <= 0 || pos.y <= 0)
            part->lifetime = 0;
        else if (part->lifetime == 1)
            sfRenderWindow_drawRectangleShape(game->window, part->shape, NULL);
        part = part->next;
    }
}

void reset_part(part_t *part, sfVector2f pos, int speed, color_t color)
{
    while (part != NULL) {
        if (speed != 0)
            part->speed = speed;
        part->lifetime = true;
        part->shape = create_particule_shape(pos, sizes[0], color);
        part = part->next;
    }
}