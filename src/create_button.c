/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_button
*/

#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

static void is_the_mouse_in(sfRectangleShape *button, sfVector2f pos,
                            sfRenderWindow *window, sfColor color)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if ((mouse_pos.x > (int)pos.x && mouse_pos.x < (int)pos.x)
    && (mouse_pos.y > (int)pos.y && mouse_pos.y < (int)pos.y))
        sfRectangleShape_setFillColor(button, color);
    else
        sfRectangleShape_setFillColor(button, sfTransparent);
}

void create_button(button_t button_to_create, sfRenderWindow *window)
{
    sfRectangleShape *button = sfRectangleShape_create();
    sfText *button_text = sfText_create();

    sfText_setFont(button_text,
                    sfFont_createFromFile(button_to_create.font_pathfile));
    sfText_setString(button_text, button_to_create.text);
    sfText_setPosition(button_text, button_to_create.position);
    sfText_setCharacterSize(button_text, button_to_create.character_size);
    sfRectangleShape_setPosition(button, button_to_create.position);
    sfRectangleShape_setSize(button, button_to_create.size);
    sfRectangleShape_setOutlineThickness(button, 1.0);
    sfRectangleShape_setOutlineColor(button, button_to_create.color);
    is_the_mouse_in(button, button_to_create.position, window,
                    button_to_create.color);
    sfRenderWindow_drawText(window, button_text, NULL);
    sfRenderWindow_drawRectangleShape(window, button, NULL);
}