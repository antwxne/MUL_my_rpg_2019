/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_textures
*/

#include <stdlib.h>
#include "game.h"
#include "filepath.h"

void destroy_texture(game_t *game)
{
    for (unsigned int i = 0; fp[i] != NULL; i++)
        sfTexture_destroy(game->textures[i]);
    free(game->textures);
}