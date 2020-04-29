/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_struct
*/

#include "fight.h"
#include "game.h"
#include "main.h"
#include "textures.h"

static bool init_array(game_t *game)
{
    game->rect_arr = (sfIntRect const **) create_rect_arr();
    game->map = load_map(map_create(), 0);
    if (!game->map || !game->rect_arr)
        return (false);
    return (true);
}

static bool init_obj_and_player(game_t *game)
{
    game->textures = create_texture();
    if (!game->textures)
        return (false);
    game->objects = load_all_object(game->textures);
    if (!game->objects)
        return (false);
    game->objects = set_position_object(game->objects, (int const **) game->map,
    game->rect_arr);
    if (!create_player(&game->player, game->objects[PLAYER][0], game->map))
        return (false);
    return (true);
}

game_t init_struct(int *ptr_err)
{
    game_t game;
    sfVideoMode mode = {window_size_x, window_size_y, 32};

    if (!init_array(&game) || !init_obj_and_player(&game)) {
        *ptr_err = -1;
        return (game);
    }
    initia_fight(&game.fight);
    game.nb_map = 0;
    game.window = sfRenderWindow_create(mode, "My_rpg", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game.window, 60);
    return (game);
}
