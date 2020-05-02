/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** enemi
*/

#include "main.h"
#include "game.h"
#include "textures.h"
#include "fight.h"

static const int enemi_type[] = {
    ENNEMI_1,
    ENNEMI_2,
    ENNEMI_3,
    -1
};

static int is_near_an_enemi(sfVector2u player_pos, int **map)
{
    for (unsigned int i = 0; enemi_type[i] != -1; i++) {
        if (player_pos.y > 0)
            if (map[player_pos.y - 1][player_pos.x] == enemi_type[i] + 1)
                return (enemi_type[i]);
        if (map[player_pos.y + 1])
            if (map[player_pos.y + 1][player_pos.x] == enemi_type[i] + 1)
                return (enemi_type[i]);
        if (player_pos.x > 0)
            if (map[player_pos.y][player_pos.x - 1] == enemi_type[i] + 1)
                return (enemi_type[i]);
        if (map[player_pos.y][player_pos.x + 1] != -1)
            if (map[player_pos.y][player_pos.x + 1] == enemi_type[i] + 1)
                return (enemi_type[i]);
    }
    return (0);
}

void use_enemy(game_t *game)
{
    int ret = is_near_an_enemi(game->player.pos_arr, game->map);

    if (ret != 0 && click_on_obj(game->event, game->window,
        game->objects[ret][0])) {
            if (ret == ENNEMI_1)
                game->view = FIGHT_1;
            if (ret == ENNEMI_2)
                game->view = FIGHT_2;
            if (ret == ENNEMI_3)
                game->view = FIGHT_3;
    }
}