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

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    game_t game = init_struct();

    show_window(&game);
    return (0);
}