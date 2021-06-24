/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display
*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "game.h"
/**
 * @brief display the map
 * @param game
 * @param map
 * @param shape
 */
void display_map(game_t *game, int map, sfRectangleShape *shape);
/**
 * @brief display start menu
 * @param window
 * @param buttons
 * @param back_ground
 * @param game
 */
void display_menu_start(sfRenderWindow *window, button_display_t *buttons,
    object_t back_ground, game_t *game);
/**
 * @brief display pause menu
 * @param window
 * @param buttons
 * @param back_ground
 * @param game
 */
void display_menu_pause(sfRenderWindow *window, button_display_t *buttons,
    object_t back_ground, game_t *game);
/**
 * @brief display end menu
 * @param window
 * @param buttons
 * @param back_ground
 * @param game
 */
void display_menu_end(sfRenderWindow *window,
    button_display_t *buttons, object_t back_ground[], game_t *game);

#endif /* !DISPLAY_H_ */
