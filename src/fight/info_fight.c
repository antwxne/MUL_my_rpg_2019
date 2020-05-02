/*
** EPITECH PROJECT, 2020
** info
** File description:
** fight
*/

#include "game.h"
#include "dialogue.h"
#include "textures.h"

void damage_fight_player(game_t *game)
{
    if (game->player.stat[0] < 0)
        game->player.stat[0] = 0;
}

void damage_fight_ennemies(game_t *game, int ennemies)
{
    if (game->fight.life_ennemie[ennemies] < 0)
        game->fight.life_ennemie[ennemies] = 0;
}

void resize_life_pl(game_t *game)
{
    sfRectangleShape_setSize(game->fight.fight_rects[6],
    (sfVector2f) {game->player.stat[0], 100});
}
