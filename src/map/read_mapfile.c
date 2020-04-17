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

read_t *get_info_buffer(char *buff)
{
    read_t *element = malloc(sizeof(read_t));
    char *temp = &buff[0];

    if (!element || !buff)
        return (NULL);
    element->type = my_getnbr(temp);
    temp = &temp[my_strlen_c(temp, ' ')];
    element->pos.x = my_getnbr(temp);
    temp = &temp[my_strlen_c(temp, ' ')];
    element->pos.y = my_getnbr(temp);
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