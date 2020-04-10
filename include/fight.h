/*
** EPITECH PROJECT, 2020
** fight
** File description:
** fight
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

typedef struct rectangle {
    sfRectangleShape **fight_rects;
} rectangle_t;

void get_mainposition(sfSprite *sprite, int x, int y);
int initia_fight(rectangle_t *rect);
int init_rectangle(rectangle_t *rects);

#endif /* !FIGHT_H_ */
