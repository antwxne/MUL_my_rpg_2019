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
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (game->view == MAP)
        display_map(window, objects, game->nb_map, game->cursor_rect);
    if (game->view == MENU_S)
        display_menu_start(window, buttons, objects[START_MENU][0]);
    if (game->view == MENU_P)
        display_menu_pause(window, buttons, objects[PAUSE_MENU][0]);
    sfSprite_setPosition(objects[CURSOR][0].sprite,
    (sfVector2f) {(float) mouse_pos.x, (float) mouse_pos.y});
    sfRenderWindow_drawSprite(window, objects[CURSOR][0].sprite, NULL);
}
