/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_map
*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "game.h"
#include "my.h"

static float check_coord(int coord, int const max)
{
    if (coord < max && coord >= 0)
        return ((float) coord);
    else {
        my_putstr("invalid position\n");
        return (-1000);
    }
}

read_t *get_info_buffer(char *buff)
{
    read_t *element = malloc(sizeof(read_t));
    char **info = my_split(buff, ' ');

    if (!element || !buff)
        return (NULL);
    element->type = my_getnbr(info[0]);
    element->pos.x = check_coord(my_getnbr(info[1]), window_size_x/rect_size+1);
    element->pos.y = check_coord(my_getnbr(info[2]), window_size_y/rect_size+1);
    free_char_arr(info, 0);
    return (element);
}

bool open_and_read_map(char const *filepath, read_t **list)
{
    read_t *element;
    FILE *fd = fopen(filepath, "r");
    char *buff = NULL;
    size_t size = 0;

    if (!fd) {
        fclose(fd);
        return (false);
    }
    for (; getline(&buff, &size, fd) != -1;) {
        element = get_info_buffer(buff);
        if (!element)
            return (false);
        element->next = *list;
        *list = element;
    }
    free(buff);
    fclose(fd);
    return (true);
}