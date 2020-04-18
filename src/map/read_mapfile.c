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

static unsigned int my_strlen_c(char const *str, char const c)
{
    unsigned int len = 0;

    if (str == NULL)
        return (0);
    for (; str[len] != '\0' && str[len] != c; len++);
    return (len);
}

static float check_coord(int coord, unsigned int const max)
{
    if (coord < max)
        return ((float) coord);
    else {
        my_putstr("invalid position\n");
        return (-1000);
    }
}

read_t *get_info_buffer(char *buff)
{
    read_t *element = malloc(sizeof(read_t));
    char *temp = &buff[0];

    if (!element || !buff)
        return (NULL);
    element->type = my_getnbr(temp);
    temp = &temp[my_strlen_c(temp, ' ')];
    element->pos.x = check_coord(my_getnbr(temp), window_size_x/rect_size+1);
    temp = &temp[my_strlen_c(temp, ' ')];
    element->pos.y = check_coord(my_getnbr(temp), window_size_y/rect_size+1);
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