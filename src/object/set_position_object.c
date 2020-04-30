/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_position_object
*/

#include <stdlib.h>
#include "game.h"
#include "filepath.h"

object_t **set_position_background(object_t **objects);

static object_t **reset_object(object_t **obj)
{
    for (unsigned int y = 0; fp[y] != NULL; y++)
        for (unsigned int x = 0; x < number_objects; x++)
            obj[y][x].position.x = -50000;
    return (obj);
}

static sfVector2f central_position(sfVector2f obj_pos, sfIntRect obj_rect,
    sfIntRect rect)
{
    obj_pos.x += (rect.width - obj_rect.width) / 2;
    obj_pos.y += (rect.height - obj_rect.height) / 2;
    return (obj_pos);
}

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
    objects[nb_obj].position = central_position(objects[nb_obj].position,
        objects[nb_obj].rect, rect);
    sfSprite_setPosition(objects[nb_obj].sprite, objects[nb_obj].position);
    return (objects);
}

object_t **set_position_object(object_t **objects, int const **map,
    sfIntRect const **rect_arr)
{
    objects = reset_object(objects);
    for (unsigned int y = 0; map[y] != NULL; y++)
        for (unsigned int x = 0; map[y][x] != -1; x++) {
            if (map[y][x] != 0)
                objects[map[y][x] - 1] = set_on_rect(objects[map[y][x] - 1],
                    rect_arr[y][x]);
        }
    return (set_position_background(objects));
}