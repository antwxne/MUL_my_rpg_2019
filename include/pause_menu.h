/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu
*/

#ifndef PAUSE_MENU_H_
#define PAUSE_MENU_H_

#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>

void create_button(button_t button_to_create, sfRenderWindow *window);

static const button_t pause_menu_resume = {(sfVector2f) {870.0, 500.0},
                                (sfVector2f) {205.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {870, 500, 205, 70}, 50,
                                "assets/font_medieval.ttf", "Resume"};

static const button_t pause_menu_main_menu = {(sfVector2f) {840.0, 580.0},
                                (sfVector2f) {295.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {840, 580, 295, 70}, 50,
                                "assets/font_medieval.ttf", "Main menu"};

static const button_t pause_menu_save = {(sfVector2f) {905.0, 660.0},
                                (sfVector2f) {125.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {905, 660, 120, 70}, 50,
                                "assets/font_medieval.ttf", "Save"};

static const button_t pause_menu_load = {(sfVector2f) {905.0, 740.0},
                                (sfVector2f) {125.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {905, 740, 125, 70}, 50,
                                "assets/font_medieval.ttf", "Load"};

static const button_t pause_menu_option = {(sfVector2f) {870.0, 820.0},
                                (sfVector2f) {205.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {870, 820, 205, 70}, 50,
                                "assets/font_medieval.ttf", "Options"};

static const button_t pause_menu_quit = {(sfVector2f) {915.0, 900.0},
                                (sfVector2f) {120.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {915, 900, 120, 70}, 50,
                                "assets/font_medieval.ttf", "Quit"};

static const button_t pause_menu_buttons[] = {
    pause_menu_resume,
    pause_menu_main_menu,
    pause_menu_save,
    pause_menu_load,
    pause_menu_option,
    pause_menu_quit
};

#endif /* !PAUSE_MENU_H_ */
