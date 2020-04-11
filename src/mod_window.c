/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mod_window
*/

#include "game.h"

static const sfVector2u size[] = {{720, 420},
                                {1280, 720},
                                {1920, 1080}};

void change_window_size(sfRenderWindow **window, unsigned int const i)
{
    sfRenderWindow_setSize(*window, size[i]);
}