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

typedef enum dir_move {
    NONE = -1,
    UP,
    DOWN,
    LEFT,
    RIGHT,
} dir_move_t;

typedef enum dir_anim {
    LEFT_ANIM,
    TOP_ANIM,
} dir_anim_t;

typedef struct anim {
    int offset;
    int max;
    float time_clock;
} anim_t;

typedef struct object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
} object_t;

typedef struct player {
    object_t ptr_obj;
    sfVector2u pos_arr;
    int dir;
    sfVector2f reach;
    sfClock *clock;
} player_t;

typedef struct game{
    sfEvent event;
    sfRenderWindow *window;
    sfTexture **textures;
    object_t **objects;
    sfIntRect const **rect_arr;
    player_t player;
    int **map;
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

#endif /* !GAME_H_ */
