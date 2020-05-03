/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_dia
*/

#include <stdlib.h>
#include "game.h"
#include "destroy.h"

void destroy_dia(game_t *game)
{
    sfText_destroy(game->dialogue.texte);
    sfFont_destroy(game->dialogue.police);
    for (unsigned int i = 0; i < 2; i++)
        sfRectangleShape_destroy(game->dialogue.dia_rects[i]);
    free(game->dialogue.dia_rects);
    for (unsigned int y = 0; y < 6; y++)
        free(game->dialogue.dia[y]);
    free(game->dialogue.dia);
}