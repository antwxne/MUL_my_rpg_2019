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

typedef enum dir_anim {
    LEFT,
    TOP,
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

typedef struct game{
    sfEvent event;
    sfRenderWindow *window;
    sfTexture ***textures;
    object_t **objects;
} game_t;

static const unsigned int window_size_x = 1920;
static const unsigned int window_size_y = 1080;
static const unsigned int rect_size = 50;

#endif /* !GAME_H_ */
