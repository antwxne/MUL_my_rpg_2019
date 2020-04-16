/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_struct
*/

#include "game.h"
#include "main.h"

game_t init_struct(int *ptr_err)
{
    game_t game;
    sfVideoMode mode = {window_size_x, window_size_y, 32};

    game.textures = create_texture();
    if (game.textures == NULL) {
        *ptr_err = -1;
        return (game);
    }
    game.objects = load_all_object(game.textures);
    if (game.objects == NULL) {
        *ptr_err = -1;
        return (game);
    }
    game.window = sfRenderWindow_create(mode, "My_rpg", sfDefaultStyle, NULL);
    return (game);
}