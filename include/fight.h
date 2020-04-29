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
#include <stdbool.h>
#include "game.h"

enum ennemies_nbr{
    MERMS_DEF,
    SHEEP_DEF,
    PIGS_DEF,
};

int battle(int status, rectangle_t *rects);
void get_mainposition(sfSprite *sprite, int x, int y);
int init_rectangle(rectangle_t *rects);
void touch(rectangle_t *rec, game_t *game);
int get_status(rectangle_t *rec, sfEvent event, sfRenderWindow *window);
void get_echap(game_t *png, rectangle_t *rects);
void draw_sprite(sfRenderWindow *window,
sfRectangleShape **fight_rects, object_t **objects);
void damage(rectangle_t *rects, int ennemies, int deg_ennemies);
void set_position(int x, int y, sfSprite *sprite);
void position_sprite(game_t *png);
int life_time(rectangle_t *rects, int ennemies);
void battle_prin(rectangle_t *rects, sfRenderWindow *window,
object_t **objects);
void god_moding(rectangle_t *rects, int ennemies, sfRenderWindow *window,
object_t **objects);
void state_effect(rectangle_t *rects, int status, int ennemies,
int ennemies_damage);
void change_color(rectangle_t *rects);
int initia_fight(rectangle_t *rects);
int fight(game_t *png, int ennemie, int name_ennemies, int ennemies_damage);

#endif /* !FIGHT_H_ */
