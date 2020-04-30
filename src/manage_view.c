/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_view
*/

#include "game.h"
#include "main.h"
#include "textures.h"
#include "fight.h"

void manage_view(game_t *game)
{
    if (game->view == MAP)
        manage_player(&game->player);
    // if (game->view == FIGHT)
    //     fight(game, MERMS, MERMS_DEF, 50);
    // if (game->view == MENU_P)
    if (game->view == MENU_S)
        manage_start_menu(game);
    // if (game->view == INVENTORY)
}