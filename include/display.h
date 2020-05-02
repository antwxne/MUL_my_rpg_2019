/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display
*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "game.h"

void display_map(game_t *game, int map, sfRectangleShape *shape);
void display_menu_start(sfRenderWindow *window, button_display_t *buttons,
    object_t back_ground, game_t *game);
void display_menu_pause(sfRenderWindow *window, button_display_t *buttons,
    object_t back_ground, game_t *game);
void display_menu_end(sfRenderWindow *window,
    button_display_t *buttons, object_t back_ground[], game_t *game);

#endif /* !DISPLAY_H_ */
