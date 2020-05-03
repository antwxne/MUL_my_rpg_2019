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

    if (size == 4) {
        size += read(fd, &game->player.armor, sizeof(int));
        size += read(fd, &game->player.weapon, sizeof(int));
        for (unsigned int i = 0; i < 4; i++)
            size += read(fd, &game->player.stat[i], sizeof(int));
    }
    if (size != 28)
        my_putstr("Save file corrupted\n");
}

void load_stat(game_t *game)
{
    int fd = open(fp_save, O_RDONLY);

    game->nb_map = 0;
    game->player.armor = 1;
    game->player.weapon = 1;
    game->player.max_health = 400;
    game->player.stat[HEALTH] = 400;
    game->player.stat[DEF_PLAYER] = 70;
    game->player.stat[ATK_PLAYER] = 145;
    game->player.stat[LVL_PLAYER] = 0;
    if (fd != -1) {
        read_stat(fd, game);
        close(fd);
    }
}
