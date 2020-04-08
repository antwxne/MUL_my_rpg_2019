/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "game.h"

object_t create_object(sfIntRect rect, sfVector2f position, sfTexture *texture);
game_t init_struct(int *ptr_err);
int show_window(game_t *game);
sfTexture ***create_texture(void);
object_t **load_all_object(sfTexture ***textures);

#endif /* !MAIN_H_ */
