/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_dialogue
*/

#include "game.h"
#include "main.h"
#include "dialogue.h"

void manage_dialogue(game_t *game)
{
    if (game->player.stat[LVL_PLAYER] == 1)
        main_dialogue(&game->dialogue, game, 2);
    if (game->player.stat[LVL_PLAYER] == 3)
        main_dialogue(&game->dialogue, game, 2);
    if (game->player.stat[LVL_PLAYER] == 5)
        main_dialogue(&game->dialogue, game, 2);
}