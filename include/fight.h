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
#include "game.h"
#include <stdbool.h>

enum ennemies_nbr{
    tarentula,
    tatou,
};


typedef struct rectangle {
    sfRectangleShape **fight_rects;
    bool etat;
    sfClock *life_clock;
    int message;
    int *life_ennemie;
} rectangle_t;

void get_mainposition(sfSprite *sprite, int x, int y);
int initia_fight(rectangle_t *rect);
int init_rectangle(rectangle_t *rects);
void touch(rectangle_t *rec, game_t *game);
int get_status(rectangle_t *rec, sfEvent event, sfRenderWindow *window);
void life_time(rectangle_t *rects, int status, sfRenderWindow *window);

#endif /* !FIGHT_H_ */
