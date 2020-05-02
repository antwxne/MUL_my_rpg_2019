/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_sprite
*/

#include "textures.h"
#include "display.h"

void display(sfRenderWindow *window, object_t **objects,
    button_display_t *buttons, game_t *game)
{
    if (game->view == MAP || game->view == DIALOGUE)
        display_map(game, game->nb_map, game->cursor.cursor_rect);
    if (game->view == MENU_S)
        display_menu_start(window, buttons, objects[START_MENU][0], game);
    if (game->view == MENU_P)
        display_menu_pause(window, buttons, objects[PAUSE_MENU][0], game);
}
