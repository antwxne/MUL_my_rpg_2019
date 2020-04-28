/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check_move
*/

#include <criterion/criterion.h>
#include "game.h"
#include "main.h"

static bool check_up(int **map, sfVector2u pos)
{
    if (pos.y > 0)
        if (map[pos.y - 1][pos.x] == 0)
            return (true);
    return (false);
}

static bool check_down(int **map, sfVector2u pos)
{
    if (map[pos.y + 1])
        if (map[pos.y + 1][pos.x] == 0)
            return (true);
    return (false);
}

static bool check_left(int **map, sfVector2u pos)
{
    if (pos.x > 0)
        if (map[pos.y][pos.x - 1] == 0)
            return (true);
    return (false);
}

static bool check_right(int **map, sfVector2u pos)
{
    if (map[pos.y][pos.x + 1] != -1)
        if (map[pos.y + 1][pos.x] == 0)
            return (true);
    return (false);
}

bool check_move(int **map, sfVector2u pos, int dir)
{
    switch (dir) {
    case (UP):
        return (check_up(map, pos));
    case (DOWN):
        return (check_down(map, pos));
    case (LEFT):
        return (check_left(map, pos));
    case (RIGHT):
        return (check_right(map, pos));
    default:
        return (false);
    }
}
