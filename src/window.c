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
#include "textures.h"
#include "window.h"

static void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

static void manage_event(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event))
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(window);
}

int show_window(game_t *game)
{
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        manage_event(game->window, &game->event);
        display_window(game->window);
        create_menu(game->window, 4, start_menu_buttons, "assets/start_menu.jpg");
    }
    sfRenderWindow_destroy(game->window);
    return (0);
}
