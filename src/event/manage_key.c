/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_key
*/

#include "game.h"
#include "main.h"

void manage_key(game_t *game)
{
    if (game->view == MAP)
        manage_key_player(&game->player, &game->map);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        manage_save(game);
}