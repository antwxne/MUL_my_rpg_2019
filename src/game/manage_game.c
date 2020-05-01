/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_game
*/

#include "main.h"
#include "game.h"

void use_pnj(game_t *game);

void manage_game(game_t *game)
{
    if (game->player.stat[3] % 2 == 0)
        use_pnj(game);
    // if (game->player.stat[3] % 2 == 1)
}