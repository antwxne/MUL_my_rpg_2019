/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pnj
*/

#include "game.h"
#include "textures.h"
#include "main.h"

static const int pnj_type[] = {
    PNJ_1,
    -1,
};

static int is_near_pnj(sfVector2u player_pos, int **map)
{
    for (unsigned int i = 0; pnj_type[i] != -1; i++) {
        if (player_pos.y > 0 &&
        (map[player_pos.y - 1][player_pos.x] == pnj_type[i] + 1))
            return (pnj_type[i]);
        if (map[player_pos.y + 1] &&
        (map[player_pos.y + 1][player_pos.x] == pnj_type[i] + 1))
            return (pnj_type[i]);
        if (player_pos.x > 0 &&
        (map[player_pos.y][player_pos.x - 1] == pnj_type[i] + 1))
            return (pnj_type[i]);
        if (map[player_pos.y][player_pos.x + 1] != -1 &&
        (map[player_pos.y][player_pos.x + 1] == pnj_type[i] + 1))
            return (pnj_type[i]);
    }
    return (0);
}

static void pnj_1(game_t *game)
{
    if (game->player.stat[3] == 0)
        game->view = DIALOGUE;
    if (game->player.stat[3] == 2)
        main_dialogue(&game->dialogue, game, 2);
    if (game->player.stat[3] == 4)
        main_dialogue(&game->dialogue, game, 2);
    game->player.stat[3] += 1;
}

void use_pnj(game_t *game)
{
    int ret = is_near_pnj(game->player.pos_arr, game->map);

    if (ret != 0 && click_on_obj(game->event, game->window,
        game->objects[ret][0])) {
        if (ret == PNJ_1)
            pnj_1(game);
    }
}
