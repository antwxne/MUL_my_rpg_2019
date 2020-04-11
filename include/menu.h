/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_

#include "button.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>

void create_button(button_t button_to_create, sfRenderWindow *window);

static const button_t start_menu_start = {(sfVector2f) {890.0, 500.0},
                                (sfVector2f) {135.0, 60.0},
                                (sfColor) {25, 25, 25, 255},
                                (sfIntRect) {890, 500, 135, 60}, 50,
                                "assets/font_medieval.ttf", "Start"};

static const button_t start_menu_how_to_play = {(sfVector2f) {790.0, 570.0},
                                (sfVector2f) {320.0, 70.0},
                                (sfColor) {25, 25, 25, 255},
                                (sfIntRect) {790, 570, 320, 70}, 50,
                                "assets/font_medieval.ttf", "How to play"};

static const button_t start_menu_option = {(sfVector2f) {850.0, 650.0},
                                (sfVector2f) {250.0, 70.0},
                                (sfColor) {25, 25, 25, 255},
                                (sfIntRect) {850, 650, 250, 70}, 50,
                                "assets/font_medieval.ttf", "Options"};

static const button_t start_menu_quit = {(sfVector2f) {890.0, 780.0},
                                (sfVector2f) {135.0, 70.0},
                                (sfColor) {25, 25, 25, 255},
                                (sfIntRect) {890, 780, 135, 70}, 50,
                                "assets/font_medieval.ttf", "Quit"};

static const button_t start_menu_buttons[] = {
    start_menu_start,
    start_menu_how_to_play,
    start_menu_option,
    start_menu_quit
};

static const button_t pause_menu_resume = {(sfVector2f) {870.0, 690.0},
                                (sfVector2f) {205.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {870, 690, 250, 70}, 50,
                                "assets/font_medieval.ttf", "Resume"};

static const button_t pause_menu_main_menu = {(sfVector2f) {840.0, 770.0},
                                (sfVector2f) {295.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {840, 770, 295, 70}, 50,
                                "assets/font_medieval.ttf", "Main menu"};

static const button_t pause_menu_option = {(sfVector2f) {870.0, 850.0},
                                (sfVector2f) {205.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {870, 840, 205, 70}, 50,
                                "assets/font_medieval.ttf", "Options"};

static const button_t pause_menu_quit = {(sfVector2f) {915.0, 960.0},
                                (sfVector2f) {120.0, 70.0},
                                (sfColor) {255, 255, 255, 255},
                                (sfIntRect) {915, 960, 130, 70}, 50,
                                "assets/font_medieval.ttf", "Quit"};

static const button_t pause_menu_buttons[] = {
    pause_menu_resume,
    pause_menu_main_menu,
    pause_menu_option,
    pause_menu_quit
};

#endif /* !MENU_H_ */
