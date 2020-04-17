/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** anim_sprite
*/

#include "game.h"

static void move_left_rect(object_t *object, int offset, int max)
{
    if (object->rect.left < max)
        object->rect.left += offset;
    else
        object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

static void move_top_rect(object_t *object, int offset, int max)
{
    if (object->rect.top < max)
        object->rect.top += offset;
    else
        object->rect.top = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void anim_object(object_t *object, anim_t animation, sfClock **ptr_clock,
    dir_anim_t dir)
{
    sfTime elapsed = sfClock_getElapsedTime(*ptr_clock);
    float time = elapsed.microseconds / 1000000.0;


    if (time > animation.time_clock && dir == LEFT) {
        move_left_rect(object, animation.offset, animation.max);
        sfClock_restart(*ptr_clock);
    }
    if (time > animation.time_clock && dir == TOP) {
        move_top_rect(object, animation.offset, animation.max);
        sfClock_restart(*ptr_clock);
    }
}