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

void create_button(button_t button_to_create, sfRenderWindow *window)
{
    sfRectangleShape *button = sfRectangleShape_create();
    sfText *button_text = sfText_create();
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(window);

    sfText_setFont(button_text,
                    sfFont_createFromFile(button_to_create.font_pathfile));
    sfText_setString(button_text, button_to_create.text);
    sfText_setPosition(button_text, button_to_create.position);
    sfText_setCharacterSize(button_text, button_to_create.character_size);
    sfRectangleShape_setPosition(button, button_to_create.position);
    sfRectangleShape_setSize(button, button_to_create.size);
    sfRectangleShape_setOutlineThickness(button, 2.0);
    sfRectangleShape_setFillColor(button, sfTransparent);
    if (sfIntRect_contains(&button_to_create.rect, m_pos.x, m_pos.y) == sfTrue)
        sfRectangleShape_setOutlineColor(button, button_to_create.color);
    else
        sfRectangleShape_setOutlineColor(button, sfTransparent);
    sfRenderWindow_drawText(window, button_text, NULL);
    sfRenderWindow_drawRectangleShape(window, button, NULL);
}