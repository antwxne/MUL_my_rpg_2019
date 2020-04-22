/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_mouse_on_rect
*/

#include "main.h"
#include "game.h"

void manage_rect(sfRenderWindow *window, sfIntRect const **rect_arr,
    sfRectangleShape *shape)
{
    sfVector2i mouse_pos = {0, 0};
    sfVector2i rect_pos = {0, 0};
    mouse_pos = sfMouse_getPositionRenderWindow(window);
    rect_pos = get_pos_int_rect(rect_arr, mouse_pos);
    move_rect_on_mouse(rect_pos, &shape);
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
}