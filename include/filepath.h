/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** filepath
*/

#ifndef FILEPATH_H_
#define FILEPATH_H_
#include <SFML/Graphics.h>

static const char *fp[] = {
    "assets/player.png",
    "assets/enemi.png",
    "assets/house.png",
    "assets/pierre.png",
    "assets/papyrus.png",
    "assets/ciseau.png",
    "assets/pegy.png",
    "assets/roi_cochon.png",
    "assets/deafet.png",
    "assets/victory.png",
    "assets/equality.png",
    NULL};

static const sfIntRect textures_rects[] = {
        {62, 545, 33, 33},
        {0, 0, 44, 46},
        {0, 0, 66, 76},
        {0, 0, 250, 250},
        {0, 0, 250, 250},
        {0, 0, 250, 250},
        {0, 0, 1920, 1080},
        {0, 0, 600, 425},
        {0, 0, 224, 80},
        {0, 0, 257, 96},
        {0, 0, 282, 97},
};

#endif /* !FILEPATH_H_ */
