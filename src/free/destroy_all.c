/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_all
*/

#include "destroy.h"
#include "main.h"
#include "particule.h"

static void destroy_hud(game_t *game)
{
    sfFont_destroy(game->font_hud);
    for (unsigned int i = 0; i < 3; i++)
        sfText_destroy(game->player.stat_txt[i]);
}

void destroy_all(game_t *game)
{
    destroy_music(game);
    destroy_objects(game);
    destroy_button(game);
    destroy_dia(game);
    destroy_hud(game);
    free_fight(&game->fight);
    sfView_destroy(game->views);
    free_rect_arr((sfIntRect **)game->rect_arr);
    free_map(game->map);
    free_part(game->fight.part);
}