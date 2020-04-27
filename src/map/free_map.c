/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free_map
*/

#include <stdlib.h>

void free_map(int **map)
{
    for (unsigned int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}