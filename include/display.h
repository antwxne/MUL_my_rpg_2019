/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display
*/

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "game.h"

void display_map(sfRenderWindow *window, object_t **objects, int map,
    sfRectangleShape *shape);
void display_menu_start(sfRenderWindow *window, button_display_t *buttons,
    object_t back_ground);
void display_menu_pause(sfRenderWindow *window, button_display_t *buttons,
    object_t back_ground);

#endif /* !DISPLAY_H_ */
