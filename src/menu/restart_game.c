/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** restart_game
*/

#include "main.h"
#include "game.h"
#include "textures.h"

static bool replace_player(player_t *player, object_t obj, int **map)
{
    player->obj = obj;
    player->dir = NONE;
    player->reach = player->obj.position;
    player->pos_arr = get_pos_player(map);
    return (player->pos_arr.x == 10000 ? false : true);
}

static void reset_enemies(rectangle_t *enemies)
{
    for (int i = 0; i <= 2; i++)
        enemies->life_ennemie[i] = 400;
    sfRectangleShape_setSize(enemies->fight_rects[3],
        (sfVector2f) {400, 100});
    enemies->my_life = 0;
}

bool restart_game(game_t *game)
{
    if (!reset_file())
        return (false);
    game->nb_map = 0;
    game->map = load_map(game->map, game->nb_map);
    game->objects = set_position_object(game->objects, (int const **) game->map,
    game->rect_arr);
    reset_enemies(&game->fight);
    if (!replace_player(&game->player, game->objects[PLAYER][0],
        game->map))
        return (false);
    load_stat(game);
    return (true);
}