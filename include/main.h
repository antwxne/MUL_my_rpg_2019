/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stdbool.h>
#include "game.h"

object_t create_object(sfIntRect rect, sfVector2f position, sfTexture *texture);
game_t init_struct(int *ptr_err);
int show_window(game_t *game);
sfTexture **create_texture(void);
object_t **load_all_object(sfTexture **textures);
object_t copy_object(object_t const object);
object_t *copy_n_object(object_t const object, unsigned int nb);
sfRectangleShape *create_rect_shape(sfVector2f const info[],
    float const thickness, sfColor const colors[]);
sfVector2i get_pos_int_rect(sfIntRect const **rect_arr, sfVector2i const m_pos);
void move_rect_on_mouse(sfVector2i const pos, sfRectangleShape **shape);
int **load_map(int **map, unsigned int map_nb);
int **map_create(void);
bool open_and_read_map(char const *filepath, read_t **list);
void free_map(int **map);
void free_rect_arr(sfIntRect **arr);
sfIntRect **create_rect_arr(void);
void manage_rect(sfRenderWindow *window, sfIntRect const **rect_arr,
    sfRectangleShape *shape);
object_t **set_position_object(object_t **objects, int const **map,
    sfIntRect const **rect_arr);
void display(sfRenderWindow *window, object_t **objects);
void move_player(player_t *player);
bool check_move(int **map, sfVector2u pos, int dir);
void manage_event(game_t *game);
void manage_key_player(player_t *player, int **map);
bool create_player(player_t *player, object_t obj, int **map);

#endif /* !MAIN_H_ */
