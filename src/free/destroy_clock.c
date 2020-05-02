/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_clock
*/

#include "game.h"

void destroy_clock(game_t *game)
{
    sfClock_destroy(game->fight.life_clock);
    sfClock_destroy(game->cursor.clock);
    sfRectangleShape_destroy(game->cursor.cursor_rect);
    sfClock_destroy(game->player.clock[0]);
    sfClock_destroy(game->player.clock[1]);
}
