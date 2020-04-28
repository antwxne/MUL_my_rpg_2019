/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_player
*/

#include "main.h"
#include "game.h"

static sfVector2u get_pos_player(int **map)
{
    sfVector2u pos = {0, 0};

    for (;map[pos.y] != NULL; pos.y++)
        for (pos.x = 0; map[pos.y][pos.x] != -1; pos.x++)
            if (map[pos.y][pos.x] == 1)
                return (pos);
    return ((sfVector2u) {10000, 0});
}

bool create_player(player_t *player, object_t obj, int **map)
{
    player->ptr_obj = obj;
    player->dir = NONE;
    player->clock = sfClock_create();
    player->reach = player->ptr_obj.position;
    player->pos_arr = get_pos_player(map);
    return (player->pos_arr.x == 10000 ? false : true);
}