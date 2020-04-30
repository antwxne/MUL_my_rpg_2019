/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_map
*/

#include <stdlib.h>
#include "game.h"
#include "main.h"

static int *line_map_empty(void)
{
    int *dest = malloc(sizeof(int *) * window_size_x / rect_size);
    unsigned int i = 0;

    if (!dest)
        return (NULL);
    for (; i < window_size_x / rect_size; i++)
        dest[i] = 0;
    dest[i] = -1;
    return (dest);
}

int **map_create(void)
{
    int **map = malloc(sizeof(int *) * (window_size_y / rect_size + 1));
    unsigned int i = 0;

    if (!map)
        return (NULL);
    for (; i < window_size_y / rect_size; i++) {
        map[i] = line_map_empty();
    }
    map[i] = NULL;
    return (map);
}