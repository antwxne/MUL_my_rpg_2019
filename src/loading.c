/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sprite
*/

#include <stdlib.h>
#include "filepath.h"
#include "game.h"
#include "main.h"

static unsigned int get_nb_type(void)
{
    unsigned int len = 0;

    for (; fp[len] != NULL; len++);
    return (len);
}

sfTexture **create_texture(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * get_nb_type());

    if (textures == NULL)
        return (NULL);
    for (unsigned int y = 0; fp[y] != NULL; y++) {
        textures[y] = sfTexture_createFromFile(fp[y], NULL);
        if (!textures[y])
            return (false);
    }
    return (textures);
}

object_t **load_all_object(sfTexture **textures)
{
    object_t **objects = malloc(sizeof(object_t *) * (get_nb_type() + 1));
    unsigned int y = 0;

    if (objects == NULL)
        return (NULL);
    for (; fp[y] != NULL; y++) {
        objects[y] = malloc(sizeof(object_t) * number_objects);
        if (objects[y] == NULL)
            return (NULL);
        for (unsigned int x = 0; x < number_objects; x++)
            objects[y][x] = create_object(textures_rects[y],
                (sfVector2f) {-50000, -50000}, textures[y]);
    }
    objects[y] = NULL;
    return (objects);
}