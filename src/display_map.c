/*
** EPITECH PROJECT, 2020
** display
** File description:
** map
*/

#include "fight.h"
#include "textures.h"
#include <stdio.h>
#include "game.h"

void display_maps(game_t *game)
{
    set_position(0, 0, game->objects[FIRST_MAP][0].sprite);
    sfRenderWindow_drawSprite(game->window, game->objects[FIRST_MAP][0].sprite, NULL);
}
