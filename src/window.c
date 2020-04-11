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

static void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

static void manage_event(sfRenderWindow **window, sfEvent *event)
{
    static unsigned int i = 0;

    while (sfRenderWindow_pollEvent(*window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(*window);
            if (event->type == sfEvtMouseButtonPressed) {
                change_window_size(window, i);
                i = i < 2 ? i + 1 : 0;
            }
    }
}

int show_window(game_t *game)
{
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        manage_event(game->window, &game->event);
        create_menu(game->window, 4, start_menu_buttons,
            "assets/start_menu.jpg");
        manage_event(&game->window, &game->event);
        display_window(game->window);
    }
    sfRenderWindow_destroy(game->window);
    return (0);
}
