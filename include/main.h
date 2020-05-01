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
void display(sfRenderWindow *window, object_t **objects,
    button_display_t *buttons, game_t *game);
void move_player(player_t *player);
bool check_move(int **map, sfVector2u pos, int dir);
void manage_event(game_t *game);
void manage_key_player(player_t *player, int ***map);
bool create_player(player_t *player, object_t obj, int **map);
void manage_player(player_t *player);
void anim_player(player_t *player);
void move_left_rect_r(object_t *object, int offset, int max);
void move_left_rect_l(object_t *object, int offset, int reset);
void move_top_rect_d(object_t *object, int offset, int max);
void move_top_rect_u(object_t *object, int offset, int reset);
void set_rect_player(player_t *player, int dir);
void manage_key(game_t *game);
void save_map(game_t *game);
void load_stat(game_t *game);
void save_stat(int nb_map, int *stat);
void manage_save(game_t *game);
button_display_t *init_button(void);
void manage_start_menu(game_t *game);
void manage_view(game_t *game);
void manage_pause_menu(game_t *game);
void change_map(game_t *game);
void manage_map(game_t *game);
void load_scene_up(game_t *game);
void load_scene_down(game_t *game);
void manage_cursor(sfRenderWindow *window, sfClock **clock,
    object_t *cursor, sfEvent event);
bool reset_file(void);
bool manage_flag(char *arg);

#endif /* !MAIN_H_ */
