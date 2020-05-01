/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_save
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "game.h"
#include "my.h"

static const char fp_save[] = ".config/save";

static void read_stat(int fd, game_t *game)
{
    int size = read(fd, &game->nb_map, sizeof(int));

    if (size == 4)
        for (unsigned int i = 0; i < 3; i++)
            size += read(fd, &game->player.stat[i], sizeof(int));
    if (size != 16)
        my_putstr("Save file corrupted\n");
}

void load_stat(game_t *game)
{
    int fd = open(fp_save, O_RDONLY);

    game->nb_map = 0;
    game->player.stat[0] = 400;
    game->player.stat[1] = 70;
    game->player.stat[2] = 50;
    game->player.armor = 1;
    game->player.weapon = 1;
    if (fd != -1) {
        read_stat(fd, game);
        close(fd);
    }
}
