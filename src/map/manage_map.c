/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_map
*/

#include "game.h"
#include "main.h"

void manage_map(game_t *game)
{
    manage_player(&game->player);
    change_map(game);
}