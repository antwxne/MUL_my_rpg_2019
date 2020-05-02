/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** manage_fight
*/

#include "main.h"
#include "game.h"
#include "fight.h"
#include "textures.h"

static void has_won(game_t *game, int name, int def, int atk)
{
    int won = fight(game, name, def, atk);

    if (won) {
        game->player.stat[3] += 1;
        game->view = MAP;
    }
}

void manage_fight(game_t *game)
{
    if (game->view == FIGHT_1)
        has_won(game, EN_1, PIGS_DEF, 50);
    if (game->view == FIGHT_2)
        has_won(game, SHEEP, SHEEP_DEF, 50);
    if (game->view == FIGHT_3)
        has_won(game, MERMS, MERMS_DEF, 50);
}