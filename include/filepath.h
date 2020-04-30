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
    "assets/perso1.png",
    "assets/png_1.png",
    "assets/house_1.png",
    "assets/pierre.png",
    "assets/papyrus.png",
    "assets/ciseau.png",
    "assets/pegy.png",
    "assets/roi_cochon.png",
    "assets/deafet.png",
    "assets/victory.png",
    "assets/equality.png",
    "assets/sheep.png",
    "assets/merms.png",
    "assets/first_map.png",
    "assets/start_menu.jpg",
    "assets/pause_menu.png",
    "assets/coolision.png",
    "assets/house_2.png",
    NULL};

static const sfIntRect textures_rects[] = {
    {32, 0, 32, 32},
    {0, 0, 32, 32},
    {0, 0, 108, 84},
    {0, 0, 250, 250},
    {0, 0, 250, 250},
    {0, 0, 250, 250},
    {0, 0, 1920, 1080},
    {0, 0, 600, 425},
    {0, 0, 224, 80},
    {0, 0, 257, 96},
    {0, 0, 282, 97},
    {0, 0, 400, 378},
    {0, 0, 450, 488},
    {0, 0, 1920, 1080},
    {0, 0, 1920, 1080},
    {0, 0, 1920, 1080},
    {0, 0, 1, 1},
    {0, 0, 99, 142},
};

#endif /* !FILEPATH_H_ */
