/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_background_pos
*/

#include "textures.h"
#include "game.h"

object_t **set_position_background(object_t **objects)
{
    for (unsigned int i = FIRST_MAP; i <= PAUSE_MENU; i++)
        sfSprite_setPosition(objects[i][0].sprite, (sfVector2f) {0, 0});
    return (objects);
}