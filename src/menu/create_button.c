/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_button
*/

#include "button.h"

button_display_t create_button(button_t button_to_create)
{
    button_display_t new_button;

    new_button.shape = sfRectangleShape_create();
    new_button.text = sfText_create();
    new_button.font = sfFont_createFromFile(button_to_create.font_pathfile);
    if (!new_button.font || !new_button.text
    || !new_button.shape)
        return (new_button);
    sfText_setFont(new_button.text, new_button.font);
    sfText_setString(new_button.text, button_to_create.text);
    sfText_setPosition(new_button.text, button_to_create.position);
    sfText_setCharacterSize(new_button.text, button_to_create.character_size);
    sfRectangleShape_setPosition(new_button.shape, button_to_create.position);
    sfRectangleShape_setSize(new_button.shape, button_to_create.size);
    sfRectangleShape_setOutlineThickness(new_button.shape, 5);
    sfRectangleShape_setFillColor(new_button.shape, sfRed);
    new_button.rect = button_to_create.rect;
    return (new_button);
}