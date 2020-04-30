/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include "button.h"

typedef enum dir_move {
    NONE = -1,
    UP,
    DOWN,
    LEFT,
    RIGHT,
} dir_move_t;

enum view_type {
    MAP,
    FIGHT,
    MENU_P,
    MENU_S,
    INVENTORY,
};

typedef struct object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
} object_t;

typedef struct player {
    object_t obj;
    sfVector2u pos_arr;
    int dir;
    sfVector2f reach;
    sfClock *clock[2];
    int stat[3];
} player_t;

typedef struct rectangle {
    sfRectangleShape **fight_rects;
    bool etat;
    bool god;
    bool consequence;
    sfClock *life_clock;
    int message;
    int *life_ennemie;
    int *def_ennemie;
    int battle_status;
} rectangle_t;

typedef struct game{
    sfEvent event;
    sfRenderWindow *window;
    sfTexture **textures;
    object_t **objects;
    sfIntRect const **rect_arr;
    button_display_t *buttons;
    player_t player;
    int **map;
    int nb_map;
    rectangle_t fight;
    int view;
    sfRectangleShape *cursor_rect;
} game_t;

typedef struct read {
    unsigned int type;
    sfVector2f pos;
    struct read *next;
} read_t;

static const unsigned int window_size_x = 1920;
static const unsigned int window_size_y = 1080;
static const unsigned int rect_size = 80;
static const unsigned int number_objects = 10;
static const float time_clock_player = 0.1;
static const float time_anim_player = 0.1;
static const unsigned int offset_move_player = 2;
static const unsigned int nb_button = 7;

#endif /* !GAME_H_ */
