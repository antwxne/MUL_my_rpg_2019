/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** management
*/

#include "main.h"
#include "game.h"

void manage_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtKeyPressed)
            manage_key_player(&game->player, &game->map);
    }
}