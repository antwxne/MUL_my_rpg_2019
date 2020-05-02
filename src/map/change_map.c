/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** change_map
*/

#include "main.h"
#include "game.h"

static const unsigned int var_range[] = {9, 9};

static bool change_scene_up(sfVector2u pos_player, unsigned int const *range)
{
    return (pos_player.y == 0 && (pos_player.x >= range[0]
        && pos_player.x <= range[1]) ? true : false);
}

static bool change_scene_down(int **map, sfVector2u pos_player,
    unsigned int const *range)
{
    unsigned int len = 0;

    for (; map[len] != NULL; len++);
    return (pos_player.y == len - 1 && (pos_player.x >= range[0]
        && pos_player.x <= range[1]) ? true : false);
}

void change_map(game_t *game)
{
    if (game->nb_map == 0 && change_scene_up(game->player.pos_arr, var_range)) {
        load_scene_up(game);
    }
    if (game->nb_map > 0 && change_scene_down(game->map, game->player.pos_arr,
        var_range))
        load_scene_down(game);
}