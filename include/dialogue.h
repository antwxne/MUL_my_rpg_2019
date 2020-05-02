/*
** EPITECH PROJECT, 2020
** dialogue
** File description:
** dialogue
*/

#include "game.h"

enum pnj_type
{
    HTP,
    PNJ_FIRST,
    PNJ_SECOND,
};

void display_maps(game_t *game);
sfRectangleShape *create_fight_rect_shape(sfVector2f pos, sfVector2f size,
sfColor color_outline, sfColor color_fill);
int how_to_play(dialogue_t *dialogue, game_t *game);
int rectangle(dialogue_t *dialogue);
void pos_dia(int x , int y, dialogue_t *dialogue, char *texte);
int wait_press_e(game_t *game);
int main_dialogue(dialogue_t *dialogue, game_t *game, int types);
int main_dialogue(dialogue_t *dialogue, game_t *game, int types);
