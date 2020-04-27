/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** window
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include "button.h"

void create_menu(sfRenderWindow *window, int nb_buttons, button_t const *button,
                char *path);

#endif /* !WINDOW_H_ */
