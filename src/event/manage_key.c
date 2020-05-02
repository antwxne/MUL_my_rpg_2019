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
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->view == MAP) {
        sfMusic_stop(game->musics[GAME_MUSIC]);
        sfMusic_play(game->musics[MENU_MUSIC]);
        game->view = MENU_P;
    }
}