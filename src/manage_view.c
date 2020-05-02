
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

void manage_dialogue(game_t *game);

void manage_view(game_t *game)
{
    if (game->view == MAP)
        manage_map(game);
    if (game->view >= FIGHT_1 && game->view <= FIGHT_3)
        manage_fight(game);
    if (game->view == MENU_P)
        manage_pause_menu(game);
    if (game->view == MENU_S)
        manage_start_menu(game);
    if (game->view == DIALOGUE)
        manage_dialogue(game);
    if (game->view == END_DIED)
}
