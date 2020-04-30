/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_save
*/

#include "main.h"
#include "game.h"

void manage_save(game_t *game)
{
    save_map(game);
    save_stat(game->nb_map, game->player.stat);
}