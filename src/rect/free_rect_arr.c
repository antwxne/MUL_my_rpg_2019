/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free_rect_arr
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

void free_rect_arr(sfIntRect **arr)
{
    for (unsigned int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}