/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "game.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdbool.h>

void set_inventory(game_t *game);
void display_sprite(sfRenderWindow *window, object_t *obj);

#endif /* !INVENTORY_H_ */
