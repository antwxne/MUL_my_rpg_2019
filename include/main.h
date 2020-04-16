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
object_t copy_object(object_t const object);
object_t *copy_n_object(object_t const object, unsigned int nb);
sfRectangleShape *create_rect_shape(sfVector2f const info[],
    float const thickness, sfColor const colors[]);
sfVector2i get_pos_int_rect(sfIntRect const **rect_arr, sfVector2i const m_pos);
void move_rect_on_mouse(sfVector2i const pos, sfRectangleShape **shape);

#endif /* !MAIN_H_ */
