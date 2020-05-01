/*
** EPITECH PROJECT, 2020
** 42
** File description:
** 42
*/

#ifndef PARTICULE_H_
#define PARTICULE_H_

#include <stdlib.h>
#include "game.h"
#include "rect_shape.h"

sfVector2f random_vector(void);
void update_part(part_t *part, sfRenderWindow *window);
part_t *create_part(int nb_part, sfVector2f pos, int speed, color_t color);
void reset_part(part_t *part, sfVector2f pos, int speed, color_t color);
void free_part(part_t *part);
sfRectangleShape *create_particule_shape(sfVector2f pos, sfVector2f size,
    color_t color);

#endif