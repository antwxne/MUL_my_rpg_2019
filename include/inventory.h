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

static inline int is_the_mouse_in_x(sfVector2i pos, int x_min, int x_max)
{
    return ((pos.x < x_max && pos.x > x_min) ? 1 : 0);
}

static inline int is_the_mouse_in_y(sfVector2i pos, int y_min, int y_max)
{
    return ((pos.y < y_max && pos.y > y_min) ? 1 : 0);
}

static inline void change_armor(game_t *game)
{
    if (game->player.armor == 1) {
        game->player.armor = 2;
        game->player.stat[0] += 50;
        game->player.max_health += 50;
        game->player.stat[1] += 10;
    } else {
        game->player.armor = 1;
        game->player.stat[0] -= 50;
        game->player.max_health -= 50;
        game->player.stat[1] -= 10;
    }
}

#endif /* !INVENTORY_H_ */
