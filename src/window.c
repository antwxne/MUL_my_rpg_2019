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
#include "option_menu.h"

static void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

static void manage_event(sfRenderWindow **window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(*window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(*window);
    }
}

int show_window(game_t *game)
{
    sfIntRect **create_rect_arr(void);
    sfRectangleShape *shape = create_rect_shape(
    (sfVector2f[2]) {{0, 0}, {rect_size, rect_size}},
        5, (sfColor[2]) {sfRed, sfWhite});
    sfIntRect const **rect_arr = (sfIntRect const **) create_rect_arr();
    sfVector2i mouse_pos = {0, 0};
    sfVector2i rect_pos = {0, 0};

    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        manage_event(&game->window, &game->event);
        mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        rect_pos = get_pos_int_rect(rect_arr, mouse_pos);
        move_rect_on_mouse(rect_pos, &shape);
        display_window(game->window);
        sfRenderWindow_drawRectangleShape(game->window, shape, NULL);

    }
    sfRenderWindow_destroy(game->window);
    return (0);
}
