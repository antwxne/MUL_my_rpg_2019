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

static int chose_map(player_t player)
{
    int level = player.stat[3];

    if (level % 2 == 0)
        return (1);
    if (level == 1)
        return (2);
    if (level == 3)
        return (3);
    if (level == 5)
        return (4);
    return (1);
}

void load_scene_up(game_t *game)
{
    game->nb_map = chose_map(game->player);
    game->map = load_map(game->map, game->nb_map);
    game->map = set_player_up(game->map, &game->player);
    game->objects = set_position_object(game->objects,
    (int const **) game->map, game->rect_arr);
    game->player.obj = game->objects[PLAYER][0];
    game->player.reach = game->objects[PLAYER][0].position;
    game->player.dir = NONE;
}