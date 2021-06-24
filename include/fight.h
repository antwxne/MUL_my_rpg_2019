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
#include "particule.h"
/**
 * @brief different types of ennemies
 * @enum ennemies_nbr
 */
enum ennemies_nbr {
    MERMS_DEF,
    SHEEP_DEF,
    PIGS_DEF,
};
/**
 * @brief manage battle
 * @param status
 * @param rects
 * @return
 */
int battle(int status, rectangle_t *rects);
/**
 * @brief get position
 * @param sprite
 * @param x
 * @param y
 */
void get_mainposition(sfSprite *sprite, int x, int y);
/**
 * @init rectangle for fight
 * @param rects
 * @return
 */
int init_rectangle(rectangle_t *rects);
/**
 * @brief touch
 * @param rec
 * @param game
 */
void touch(rectangle_t *rec, game_t *game);
/**
 * @brief get status
 * @param rec
 * @param event
 * @param window
 * @return
 */
int get_status(rectangle_t *rec, sfEvent event, sfRenderWindow *window);
/**
 * @brief get input echap key
 * @param png
 * @param rects
 */
void get_echap(game_t *png, rectangle_t *rects);
/**
 * @brief draw sprite
 * @param window
 * @param fight_rects
 * @param objects
 */
void draw_sprite(sfRenderWindow *window,
sfRectangleShape **fight_rects, object_t **objects);
/**
 * @brief reduce life
 * @param game
 * @param ennemies
 * @param deg_ennemies
 */
void damage(game_t *game, int ennemies, int deg_ennemies);
/**
 * @brief set position
 * @param x
 * @param y
 * @param sprite
 */
void set_position(int x, int y, sfSprite *sprite);
/**
 * @brief set default position
 * @param png
 */
void position_sprite(game_t *png);
/**
 * @brief lifetime
 * @param rects
 * @param ennemies
 * @param game
 * @return
 */
int life_time(rectangle_t *rects, int ennemies, game_t *game);
/**
 * @brief display battle
 * @param rects
 * @param window
 * @param objects
 */
void battle_prin(rectangle_t *rects, sfRenderWindow *window,
object_t **objects);
/**
 * @brief set god mod on
 * @param rects
 * @param ennemies
 * @param window
 * @param objects
 */
void god_moding(rectangle_t *rects, int ennemies, sfRenderWindow *window,
object_t **objects);
/**
 * @brief state effect
 * @param game
 * @param status
 * @param ennemies
 * @param ennemies_damage
 */
void state_effect(game_t *game, int status, int ennemies,
int ennemies_damage);
/**
 * @brief change color
 * @param rects
 */
void change_color(rectangle_t *rects);
/**
 * @brief inint fight
 * @param rects
 * @return
 */
int initia_fight(rectangle_t *rects);
/**
 * @brief fight
 * @param png
 * @param enemy
 * @param name_enemies
 * @param enemies_damage
 * @return
 */
int fight(game_t *png, int enemy, int name_enemies, int enemies_damage);
/**
 * @brief reduce player life
 * @param game
 */
void damage_fight_player(game_t *game);
/**
 * @brief reduce enemy life
 * @param game
 * @param enemies
 */
void damage_fight_ennemies(game_t *game, int enemies);
/**
 * @brief change player life rect
 * @param game
 */
void resize_life_pl(game_t *game);

#endif /* !FIGHT_H_ */
