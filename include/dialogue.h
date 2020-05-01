/*
** EPITECH PROJECT, 2020
** dialogue
** File description:
** dialogue
*/

#include "game.h"

typedef struct dialogue {
    sfRectangleShape **dia_rects;
    sfFont *police;
    sfText *texte;
    char ***dia;
} dialogue_t;

void display_maps(game_t *game);
sfRectangleShape *create_fight_rect_shape(sfVector2f pos, sfVector2f size,
sfColor color_outline, sfColor color_fill);
