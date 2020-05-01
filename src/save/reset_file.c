/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** reset_file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "game.h"
#include "my.h"
#include "save.h"

static const char *content_map[] = {
    "3 1 0\n3 3 0 \n2 2 1\n3 1 2\n3 3 2\n3 19 2\n1 13 9\n18 18 4\n18 19 6\n" \
    "18 21 6\n18 19 7\n17 0 8\n17 1 9\n17 2 9\n17 3 10\n17 4 10\n17 5 11\n" \
    "17 6 12\n17 7 12"
};

static const char fp_save[] = ".config/save";

static bool reset_map(int map)
{
    int fd = open(fp_map[map], O_WRONLY);

    if (fd == -1)
        fd = open(fp_map[map], O_WRONLY | O_CREAT, rights);
    if (fd != -1) {
        write(fd, content_map[map], my_strlen(content_map[map]));
        close(fd);
        return (true);
    } else {
        my_putstr("Make sure that you have ./.config/maps folder\n");
        return (false);
    }
}

static bool reset_stat(void)
{
    int fd = open(fp_save, O_WRONLY);
    int stat[4] = {0, 400, 70, 50};

    if (fd == -1)
        fd = open(fp_save, O_WRONLY | O_CREAT, rights);
    if (fd != -1) {
        for (unsigned int i = 0; i < 4; i++)
            write(fd, &stat[i], sizeof(int));
        close(fd);
        return (true);
    } else {
        my_putstr("Make sure that you have ./.config folder\n");
        return (false);
    }
}

bool reset_file(void)
{
    if (!reset_map(0) || !reset_stat())
        return (false);
    else
        return (true);
}