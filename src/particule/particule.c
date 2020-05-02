/*
** EPITECH PROJECT, 2020
** 42
** File description:
** 42
*/

#include "particule.h"

static const sfVector2f sizes[] = {{20, 30}
};

sfRectangleShape *create_particule_shape(sfVector2f pos, sfVector2f size,
color_t color)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setOrigin(shape, (sfVector2f){0, 0});
    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setOutlineColor(shape, color.coloring);
    sfRectangleShape_setFillColor(shape, color.color_fill);
    sfRectangleShape_setOutlineThickness(shape, 7);
    return (shape);
}

part_t *list_part_create(sfVector2f pos, int speed, color_t color)
{
    part_t *part = malloc(sizeof(part_t));

    (void) speed;
    if (part != NULL) {
        part->next = NULL;
        part->shape = create_particule_shape(pos, sizes[0], color);
        part->speed = 1;
        part->direction = random_vector();
        part->lifetime = true;
    }
    return (part);
}

void push_to_part(part_t **part, sfVector2f pos, color_t color)
{
    part_t *head = *part;

    while (head->next != NULL)
        head = head->next;
    head->next = malloc(sizeof(part_t));
    head->next->shape = create_particule_shape(pos, sizes[0], color);
    head->next->speed = 1;
    head->next->direction = random_vector();
    head->next->lifetime = true;
    head->next->next = NULL;
}

part_t *create_part(int nb_part, sfVector2f pos, int speed, color_t color)
{
    int n = 0;
    part_t *part = NULL;

    while (n != nb_part) {
        if (n == 0)
            part = list_part_create(pos, speed, color);
        else
            push_to_part(&part, pos, color);
        n++;
    }
    return (part);
}