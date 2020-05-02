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

enum music {
    MENU_MUSIC,
    FIGHT_MUSIC,
    DEAD_MUSIC,
    GAME_MUSIC,
};

typedef enum dir_move {
    NONE = -1,
    UP,
    DOWN,
    LEFT,
    RIGHT,
} dir_move_t;

enum stat_player {
    HEALTH,
    DEF_PLAYER,
    ATK_PLAYER,
    LVL_PLAYER
};

enum view_type {
    MAP,
    FIGHT_1,
    FIGHT_2,
    FIGHT_3,
    MENU_P,
    MENU_S,
    DIALOGUE,
    END_DIED,
};

typedef struct dialogue {
    sfRectangleShape **dia_rects;
    sfFont *police;
    sfText *texte;
    char ***dia;
} dialogue_t;

typedef struct particule {
    sfRectangleShape *shape;
    float speed;
    sfVector2f direction;
    sfVector2f size;
    bool lifetime;
    struct particule *next;
} part_t;

typedef struct color_shape {
    sfColor coloring;
    sfColor color_fill;
} color_t;

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
    int armor;
    int weapon;
    int max_health;
    int stat[4];
    sfText *stat_txt[3];
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
    int my_life;
    part_t *part;
    dialogue_t dialogue;
} rectangle_t;

typedef struct cursor {
    sfRectangleShape *cursor_rect;
    sfClock *clock;
} cursor_t;

typedef struct game{
    sfEvent event;
    sfRenderWindow *window;
    sfMusic **musics;
    sfTexture **textures;
    object_t **objects;
    sfIntRect const **rect_arr;
    button_display_t *buttons;
    player_t player;
    int **map;
    int nb_map;
    rectangle_t fight;
    int view;
    cursor_t cursor;
    dialogue_t dialogue;
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
