/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** option_menu
*/

#ifndef OPTION_MENU_H_
#define OPTION_MENU_H_

#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>

void create_button(button_t button_to_create, sfRenderWindow *window);

static const button_t option_menu_back = {(sfVector2f) {130.0, 390.0},
                                (sfVector2f) {135.0, 70.0},
                                (sfColor) {25, 25, 25, 255},
                                (sfIntRect) {130, 390, 100, 70}, 50,
                                "assets/font_medieval.ttf", "Back"};

static const button_t option_menu_graphics = {(sfVector2f) {130.0, 150.0},
                                (sfVector2f) {235.0, 70.0},
                                (sfColor) {25, 25, 25, 255},
                                (sfIntRect) {130, 150, 235, 70}, 50,
                                "assets/font_medieval.ttf", "Graphics"};

static const button_t option_menu_sound = {(sfVector2f) {130.0, 230.0},
                                (sfVector2f) {195.0, 70.0},
                                (sfColor) {25, 25, 25, 255},
                                (sfIntRect) {130, 230, 195, 70}, 50,
                                "assets/font_medieval.ttf", "Sounds"};

static const button_t option_menu_controls = {(sfVector2f) {130.0, 310.0},
                                (sfVector2f) {215.0, 70.0},
                                (sfColor) {25, 25, 25, 255},
                                (sfIntRect) {130, 310, 250, 70}, 50,
                                "assets/font_medieval.ttf", "Controls"};

static const button_t option_menu_buttons[] = {
    option_menu_back,
    option_menu_graphics,
    option_menu_sound,
    option_menu_controls
};

#endif /* !OPTION_MENU_H_ */
