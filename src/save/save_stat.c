/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save_stat
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "game.h"
#include "main.h"

static const int rights = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;

static const char fp_save[] = ".config/save";

static void write_stat_in_file(int nb_map, int *stat, int fd)
{
    write(fd, &nb_map, sizeof(int));
    for (unsigned int i = 0; i < 3; i++)
        write(fd, &stat[i], sizeof(int));
}

void save_stat(int nb_map, int *stat)
{
    int fd = open(fp_save, O_WRONLY);

    if (fd == -1)
        fd = open(fp_save, O_WRONLY | O_CREAT, rights);
    if (fd != -1) {
        write_stat_in_file(nb_map, stat, fd);
        close(fd);
    }
}