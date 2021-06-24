/*
** EPITECH PROJECT, 2020
** dialogue
** File description:
** dialogue
*/

#include "game.h"
/**
 * @brief different types
 * @enum pnj_type
 */
enum pnj_type
{
    HTP,
    PNJ_FIRST,
    PNJ_SECOND,
};
/**
 * @brief display the map
 * @param game
 */
void display_maps(game_t *game);
/**
 * @brief create a rectangle for button in fight
 * @param pos
 * @param size
 * @param color_outline
 * @param color_fill
 * @return new rectangle
 */
sfRectangleShape *create_fight_rect_shape(sfVector2f pos, sfVector2f size,
sfColor color_outline, sfColor color_fill);
/**
 * @brief how to play
 * @param dialogue
 * @param game
 * @return
 */
int how_to_play(dialogue_t *dialogue, game_t *game);
/**
 * @brief rectangle for dialog
 * @param dialogue
 * @return
 */
int rectangle(dialogue_t *dialogue);
/**
 * @brief set position for dialogs
 * @param x
 * @param y
 * @param dialogue
 * @param texte
 */
void pos_dia(int x , int y, dialogue_t *dialogue, char *texte);
/**
 * @brief wait for input to change dialog
 * @param game
 * @return
 */
int wait_press_e(game_t *game);
/**
 * @brief main dialog
 * @param dialogue
 * @param game
 * @param types
 * @return
 */
int main_dialogue(dialogue_t *dialogue, game_t *game, int types);
