/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

static bool game_start(void)
{
    int error = 0;
    game_t game = init_struct(&error);
    int fd = open("/dev/random", O_RDONLY);

    if (fd == -1 || error == -1)
        return (false);
    read(fd, &error, sizeof(int));
    srand(error);
    close(fd);
    show_window(&game);
    free_map(game.map);
    free_part(game.fight.part);
    return (true);
}

int main(int ac, char **av, char **env)
{
    bool ret = false;

    if (env[0] == NULL)
        return (84);
    if (ac == 2)
        ret = manage_flag(av[1]);
    if (ac == 1)
        ret = game_start();
    return (ret == true ? 0 : 84);
}
