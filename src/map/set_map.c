/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_map_mask
*/

#include <stdlib.h>
#include "game.h"
#include "main.h"
#include "save.h"

static int **insert_coord_in_map(int **map, read_t *list)
{
    read_t *to_free;

    for (read_t *temp = list; temp != NULL; ) {
        if (temp->pos.y >= 0 && temp->pos.x >= 0)
            map[(int) temp->pos.y][(int) temp->pos.x] = temp->type;
        to_free = temp;
        temp = temp->next;
        free(to_free);
    }
    return (map);
}

static int **reset_map(int **map)
{
    if (!map)
        return (map);
    for (unsigned int y = 0; map[y]; y++)
        for (unsigned int x = 0; map[y][x] != -1; x++)
            map[y][x] = 0;
    return (map);
}

int **load_map(int **map, unsigned int map_nb)
{
    read_t *list = NULL;

    map = reset_map(map);
    if (!map || !open_and_read_map(fp_map[map_nb], &list))
        return (map);
    map = insert_coord_in_map(map, list);
    return (map);
}