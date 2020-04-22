/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_object
*/

#include "game.h"

object_t create_object(sfIntRect rect, sfVector2f position, sfTexture *texture)
{
    object_t element;

    element.position = position;
    element.texture = texture;
    element.sprite = sfSprite_create();
    element.rect = rect;
    sfSprite_setTexture(element.sprite, element.texture, sfTrue);
    sfSprite_setTextureRect(element.sprite, rect);
    sfSprite_setPosition(element.sprite, position);
    return (element);
}