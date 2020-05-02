/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_button
*/

#include <stdlib.h>
#include "game.h"
#include "button.h"

void destroy_button(game_t *game)
{
    for (unsigned int i = 0; i< nb_button; i++) {
        sfFont_destroy(game->buttons[i].font);
        sfRectangleShape_destroy(game->buttons[i].shape);
        sfText_destroy(game->buttons[i].text);
    }
    free(game->buttons);
}