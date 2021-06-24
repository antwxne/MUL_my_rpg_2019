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
/**
 * @brief create a random vector
 * @return
 */
sfVector2f random_vector(void);
/**
 * @brief update all particles
 * @param part
 * @param window
 */
void update_part(part_t *part, sfRenderWindow *window);
/**
 * @brief create particles
 * @param nb_part
 * @param pos
 * @param speed
 * @param color
 * @return
 */
part_t *create_part(int nb_part, sfVector2f pos, int speed, color_t color);
/**
 * @brief reset particles
 * @param part
 * @param pos
 * @param speed
 * @param color
 */
void reset_part(part_t *part, sfVector2f pos, int speed, color_t color);
/**
 * @brief free particles
 * @param part
 */
void free_part(part_t *part);
/**
 * @brief create particles shape
 * @param pos
 * @param size
 * @param color
 * @return
 */
sfRectangleShape *create_particule_shape(sfVector2f pos, sfVector2f size,
    color_t color);
/**
 * @brief make particles rain
 * @param part
 * @param game
 * @param color
 */
void rain(part_t *part, game_t *game, color_t color);

#endif