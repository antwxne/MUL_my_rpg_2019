/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_sprite
*/

#include "textures.h"
#include "display.h"

void display(sfRenderWindow *window, object_t **objects,
    button_display_t *buttons, int view)
{
    if (view == MAP)
        display_map(window, objects);
    if (view == MENU_S)
        display_menu_start(window, buttons, objects[START_MENU][0]);
}
