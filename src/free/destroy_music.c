/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_music
*/

#include <stdlib.h>
#include "game.h"
#include "main.h"

void destroy_music(game_t *game)
{
    for (unsigned int i = 0; i < 4; i++)
        sfMusic_destroy(game->musics[i]);
    free(game->musics);
}