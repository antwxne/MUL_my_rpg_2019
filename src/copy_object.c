/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** copy_object
*/

#include "game.h"

object_t copy_object(object_t const object)
{
    object_t dest;
    dest.position = object.position;
    dest.rect = object.rect;
    dest.sprite = sfSprite_copy(object.sprite);
    dest.texture = object.texture;
    return (dest);
}

object_t *copy_n_object(object_t const object, unsigned int nb)
{
    object_t *dest = malloc(sizeof(object_t) * nb);

    if (dest == NULL)
        return (NULL);
    for (unsigned int i = 0; i < nb; i++)
        dest[i] = copy_object(object);
    return (dest);
}