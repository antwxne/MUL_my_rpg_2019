/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save_game
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "game.h"
#include "main.h"
#include "my.h"

static const int rights = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;

static const char *fp_map[] = {
    ".config/maps/map_1"
};

static void write_map_in_file(int fd, int *type_x_y)
{
    char *temp;

    for (unsigned int i = 0; i < 3; i++) {
        temp = my_itoa(type_x_y[i]);
        write(fd, temp, my_strlen(temp));
        free(temp);
        write(fd, " ", 1);
    }
    write(fd, "\n", 1);
}

static void get_obj_in_map(int **map, int fd)
{

    for (unsigned int y = 0; map[y] != NULL; y++)
        for (unsigned int x = 0; map[y][x] != -1; x++)
            if (map[y][x] != 0)
                write_map_in_file(fd, (int [3]) {map[y][x], x, y});

}

void save_map(game_t *game)
{
    int fd = open(fp_map[game->nb_map], O_WRONLY);

    if (fd == -1)
        fd = open(fp_map[game->nb_map], O_WRONLY | O_CREAT, rights);
    if (fd != -1) {
        get_obj_in_map(game->map, fd);
        close(fd);
    }
}