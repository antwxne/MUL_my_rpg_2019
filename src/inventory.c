/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "inventory.h"
#include "textures.h"

void inventory(object_t *object)
{
    sfVector2f position = {500, 500};
    object[0].position = position;
    sfSprite_setPosition(object[0].sprite, position);
}