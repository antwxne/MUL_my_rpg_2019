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

static unsigned int get_nb_textures(unsigned int type)
{
    unsigned int len = 0;

    for (; fp[type][len] != NULL; len++);
    return (len);
}

sfTexture ***create_texture(void)
{
    sfTexture ***textures = malloc(sizeof(sfTexture **) * get_nb_type());

    if (textures == NULL)
        return (NULL);
    for (unsigned int y = 0; fp[y] != NULL; y++) {
        textures[y] = malloc(sizeof(sfTexture *) * get_nb_textures(y));
        if (textures[y] == NULL)
            return (NULL);
        for (unsigned int x = 0; fp[y][x] != NULL; x++)
            textures[y][x] = sfTexture_createFromFile(fp[y][x], NULL);
    }
    return (textures);
}

object_t **load_all_object(sfTexture ***textures)
{
    object_t **objects = malloc(sizeof(object_t *) * get_nb_type());

    if (objects == NULL)
        return (NULL);
    for (unsigned int y = 0; fp[y] != NULL; y++) {
        objects[y] = malloc(sizeof(object_t) * get_nb_textures(y));
        if (objects[y] == NULL)
            return (NULL);
        for (unsigned int x = 0; fp[y][x] != NULL; x++)
            objects[y][x] = create_object((sfIntRect) {0, 0, 100, 100},
                (sfVector2f) {500, 500}, textures[y][x]);
    }
    return (objects);
}