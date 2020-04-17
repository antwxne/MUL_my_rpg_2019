/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_map_mask
*/

#include <stdlib.h>
#include "game.h"
#include "main.h"

static const char *map_filepath[] = {
                ".config/maps/map_1"
                };

static int **insert_coord_in_map(int **map, read_t *list)
{
    read_t *to_free;

    for (read_t *temp = list; temp != NULL; ) {
        map[(int) temp->pos.y][(int) temp->pos.x] = temp->type;
        to_free = temp;
        temp = temp->next;
        free(to_free);
    }
    return (map);
}

int **load_map(int **map, unsigned int map_nb)
{
    read_t *list = NULL;

    if (!open_and_read_map(map_filepath[map_nb], &list))
        return (map);
    map = insert_coord_in_map(map, list);
    return (map);
}