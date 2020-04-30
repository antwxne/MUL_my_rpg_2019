/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_scene_up
*/

#include "game.h"
#include "main.h"
#include "textures.h"

static int **set_player_up(int **map, player_t *player)
{
    unsigned int y = 0;
    for (; map[y] != NULL; y++)
        for (unsigned int x = 0; map[y][x] != -1; x++)
            if (map[y][x] == 1)
                map[y][x] = 0;
    map[y - 2][player->pos_arr.x] = 1;
    player->pos_arr.y = y - 2;
    return (map);
}

void load_scene_up(game_t *game)
{
    game->map = load_map(game->map, 1);
    game->map = set_player_up(game->map, &game->player);
    game->objects = set_position_object(game->objects,
    (int const **) game->map, game->rect_arr);
    game->player.obj = game->objects[PLAYER][0];
    game->player.reach = game->objects[PLAYER][0].position;
    game->player.dir = NONE;
    game->nb_map = 1;
}