/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_struct
*/

#include "game.h"

game_t init_struct(void)
{
    game_t game;
    sfVideoMode mode = {1920, 1080, 32};

    game.window = sfRenderWindow_create(mode, "My_rpg", sfDefaultStyle, NULL);
    return (game);
}