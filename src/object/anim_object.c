/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** anim_sprite
*/

#include "game.h"

void move_left_rect(object_t *object, int offset, int max)
{
    if (object->rect.left < max)
        object->rect.left += offset;
    else
        object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void move_top_rect(object_t *object, int offset, int max)
{
    if (object->rect.top < max)
        object->rect.top += offset;
    else
        object->rect.top = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
}