/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_all
*/

#include "destroy.h"
#include "main.h"

void destroy_all(game_t *game)
{
    destroy_music(game);
    destroy_objects(game);
    destroy_button(game);
    free_rect_arr((sfIntRect **)game->rect_arr);
    free_map(game->map);
    free_part(game->fight.part);
}