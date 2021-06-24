/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hud
*/

#ifndef HUD_H_
#define HUD_H_

#include "game.h"
/**
 * @brief apply stat to player
 * @param stats
 * @param game
 */
void apply_stats(sfText **stats, game_t *game);
/**
 * @brief create hud
 * @param game
 * @return
 */
int create_hud(game_t *game);

#endif /* !HUD_H_ */
