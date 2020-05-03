/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_save
*/

#include "save.h"
#include "main.h"

bool check_save(void)
{
    int fd = 0;

    for (unsigned int i = 0; fp_map[i] != NULL; i++) {
        fd = open(fp_map[i], O_RDONLY);
        if (fd == -1) {
            if (!reset_file())
                return (false);
        } else
            close(fd);
    }
    return (true);
}