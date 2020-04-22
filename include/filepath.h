/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** filepath
*/

#ifndef FILEPATH_H_
#define FILEPATH_H_

#include <SFML/Graphics.h>

static const char *fp[] = {"assets/player.png",
                            "assets/enemi.png",
                            "assets/house.png",
                            NULL};

static const sfIntRect textures_rects[] = {
        {62, 545, 33, 33},
        {0, 0, 44, 46},
        {0, 0, 66, 76},
};

#endif /* !FILEPATH_H_ */
