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

void manage_game(game_t *game);

static void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

int show_window(game_t *game)
{
    sfMusic_play(game->musics[MENU_MUSIC]);
    while (sfRenderWindow_isOpen(game->window)) {
        manage_event(game);
        display_window(game->window);
        manage_view(game);
        display(game->window, game->objects, game->buttons, game);
        manage_cursor(game->window, &game->cursor.clock,
        &game->objects[CURSOR][0], game->event);
        manage_game(game);
    }
    free_rect_arr((sfIntRect **)game->rect_arr);
    sfRenderWindow_destroy(game->window);
    return (0);
}
