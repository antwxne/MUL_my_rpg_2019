/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** window
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "game.h"
#include "main.h"
#include "textures.h"
#include "window.h"
#include "pause_menu.h"
#include "fight.h"

static void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

int show_window(game_t *game)
{
    sfRectangleShape *shape = create_rect_shape(
    (sfVector2f[2]) {{0, 0}, {rect_size, rect_size}},
        5, (sfColor[2]) {sfRed, sfWhite});

    while (sfRenderWindow_isOpen(game->window)) {
        manage_event(game);
        // create_menu(game->window, 6, pause_menu_buttons,
        //     "assets/pause_menu.png");
        //fight(game, MERMS, MERMS_DEF, 50);
        display_window(game->window);
        manage_rect(game->window, game->rect_arr, shape);
        manage_player(&game->player);
        display(game->window, game->objects);
    }
    free_rect_arr((sfIntRect **)game->rect_arr);
    sfRenderWindow_destroy(game->window);
    return (0);
}
