/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "inventory.h"
#include "textures.h"

void inventory(float x, float y, object_t *object)
{
    object[0].position.x = x;
    object[0].position.y = y;
    sfSprite_setPosition(object[0].sprite, object[0].position);
}

void set_inventory(sfRenderWindow *window, object_t **objects)
{
    inventory(5.0, 850.0, objects[INVENTORY_]);
    inventory(37.0, 890.0, objects[SWORD]);
    inventory(80.0, 890.0, objects[ARMOR_2]);
    inventory(105.0, 875.0, objects[POTION]);
}