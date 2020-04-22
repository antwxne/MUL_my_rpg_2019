/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_position_object
*/

#include <stdlib.h>
#include "game.h"

static int get_object(object_t const *objects)
{
    int nb_object = 0;

    for (unsigned int i = 0; i < number_objects; i++, nb_object++)
        if (objects[i].position.x < 0)
            return (nb_object);
    return (-1);
}

static object_t *set_on_rect(object_t *objects, sfIntRect rect)
{
    int nb_obj = get_object(objects);

    if (nb_obj == -1)
        return (objects);
    objects[nb_obj].position.x = rect.left;
    objects[nb_obj].position.y = rect.top;
    sfSprite_setPosition(objects[nb_obj].sprite, objects[nb_obj].position);
    return (objects);
}

object_t **set_position_object(object_t **objects, int const **map,
    sfIntRect const **rect_arr)
{
    for (unsigned int y = 0; map[y] != NULL; y++)
        for (unsigned int x = 0; map[y][x] != -1; x++) {
            if (map[y][x] != 0)
                objects[map[y][x] - 1] = set_on_rect(objects[map[y][x] - 1],
                    rect_arr[y][x]);
        }
    return (objects);
}