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
    "3 1 0\n3 3 0 \n2 2 1\n3 1 2\n3 3 2\n3 19 2\n1 13 9\n19 18 4\n19 19 6\n" \
    "19 21 6\n18 19 7\n17 0 8\n17 1 9\n17 2 9\n17 3 10\n17 4 10\n17 5 11\n17 6 12\n17 7 12",
    "",
    "27 1 2",
    "28 17 2",
    "29 21 9"
};

static const char fp_save[] = ".config/save";

static const char *error_msg[] = {
    "\033[91;1;5;4mERROR\033[0m:Make sure that you have ./.config/maps folder\n",
    "\033[91;1;5;4mERROR\033[0m:Make sure that you have ./.config folder\n",
};

static bool reset_map(int map)
{
    int fd = open(fp_map[map], O_WRONLY);

    if (fd == -1)
        fd = open(fp_map[map], O_WRONLY | O_CREAT, rights);
    if (fd != -1) {
        write(fd, content_map[map], my_strlen(content_map[map]));
        close(fd);
        return (true);
    } else
        return (false);
}

static bool reset_stat(void)
{
    int fd = open(fp_save, O_WRONLY);
    int stat[5] = {0, 400, 70, 50, 0};

    if (fd == -1)
        fd = open(fp_save, O_WRONLY | O_CREAT, rights);
    if (fd != -1) {
        for (unsigned int i = 0; i < 5; i++)
            write(fd, &stat[i], sizeof(int));
        close(fd);
        return (true);
    } else {
        my_putstr((char *) error_msg[1]);
        return (false);
    }
}

static bool reset_all_maps(void)
{
    for (unsigned int i = 0; i < 5; i++)
        if (!reset_map(i)) {
            my_putstr((char *) error_msg[0]);
            return (false);
        }
    return (true);
}

bool reset_file(void)
{
    if (!reset_all_maps() || !reset_stat())
        return (false);
    else {
        my_putstr("Reset \033[92;1mOK\033[0m\n");
        return (true);
    }
}