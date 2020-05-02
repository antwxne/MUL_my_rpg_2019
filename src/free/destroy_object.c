/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_object
*/

#include <stdlib.h>
#include "game.h"
#include "main.h"
#include "filepath.h"

void destroy_objects(game_t *game)
{
    for (unsigned int y = 0; fp[y] != NULL; y++) {
        for (unsigned int x = 0; x < number_objects; x++)
            sfSprite_destroy(game->objects[y][x].sprite);
        free(game->objects[y]);
    }
}