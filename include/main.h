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
/**
 * @brief create an object
 * @param rect
 * @param position
 * @param texture
 * @return
 */
object_t create_object(sfIntRect rect, sfVector2f position, sfTexture *texture);
/**
 * @brief init all the game struct
 * @param ptr_err
 * @return
 */
game_t init_struct(int *ptr_err);
/**
 * @brief display the window
 * @param game
 * @return
 */
int show_window(game_t *game);
/**
 * @brief load all textures
 * @return textures array
 */
sfTexture **create_texture(void);
/**
 * @brief create all objects
 * @param textures
 * @return objects array
 */
object_t **load_all_object(sfTexture **textures);
/**
 * @brief copy an object
 * @param object
 * @return new object
 */
object_t copy_object(object_t const object);
/**
 * @brief copy n times an object
 * @param object
 * @param nb
 * @return object array
 */
object_t *copy_n_object(object_t const object, unsigned int nb);
/**
 * @brief create a rectangle
 * @param info
 * @param thickness
 * @param colors
 * @return new rectangle
 */
sfRectangleShape *create_rect_shape(sfVector2f const info[],
    float const thickness, sfColor const colors[]);
/**
 * @brief get position of a rectangle in rectangle array
 * @param rect_arr
 * @param m_pos
 * @return position
 */
sfVector2i get_pos_int_rect(sfIntRect const **rect_arr, sfVector2i const m_pos);
/**
 * @brief set a rectangle under the cursor
 * @param pos
 * @param shape
 */
void move_rect_on_mouse(sfVector2i const pos, sfRectangleShape **shape);
/**
 * @brief load map
 * @param map
 * @param map_nb
 * @return map
 */
int **load_map(int **map, unsigned int map_nb);
/**
 * @brief create a new map
 * @return new map
 */
int **map_create(void);
/**
 * @brief read a map from configuration file
 * @param filepath
 * @param list
 * @return fail or not
 */
bool open_and_read_map(char const *filepath, read_t **list);
/**
 * @brief free map
 * @param map
 */
void free_map(int **map);
/**
 * @brief free int rect array
 * @param arr
 */
void free_rect_arr(sfIntRect **arr);
/**
 * @brief create rectangle array
 * @return new rectangle array
 */
sfIntRect **create_rect_arr(void);
/**
 * @brief manage rectangle under mouse
 * @param window
 * @param rect_arr
 * @param shape
 */
void manage_rect(sfRenderWindow *window, sfIntRect const **rect_arr,
    sfRectangleShape *shape);
/**
 * @brief set objects position on map
 * @param objects
 * @param map
 * @param rect_arr
 * @return objects with position updated
 */
object_t **set_position_object(object_t **objects, int const **map,
    sfIntRect const **rect_arr);
/**
 * @brief display objects
 * @param window
 * @param objects
 * @param buttons
 * @param game
 */
void display(sfRenderWindow *window, object_t **objects,
    button_display_t *buttons, game_t *game);
/**
 * @brief move the player
 * @param player
 */
void move_player(player_t *player);
/**
 * @brief check collisions
 * @param map
 * @param pos
 * @param dir
 * @return collision or not
 */
bool check_move(int **map, sfVector2u pos, int dir);
/**
 * @brief manage input event
 * @param game
 */
void manage_event(game_t *game);
/**
 * @brief interpret key input to move the player
 * @param player
 * @param map
 */
void manage_key_player(player_t *player, int ***map);
/**
 * @brief create a new player
 * @param player
 * @param obj
 * @param map
 * @return succes or not
 */
bool create_player(player_t *player, object_t obj, int **map);
/**
 * @brief manage player infos
 * @param player
 */
void manage_player(player_t *player);
/**
 * @brief animation for the player
 * @param player
 */
void anim_player(player_t *player);
/**
 * @brief move object's rect to right
 * @param object
 * @param offset
 * @param max
 */
void move_left_rect_r(object_t *object, int offset, int max);
/**
 * @brief move object's rect to left
 * @param object
 * @param offset
 * @param max
 */
void move_left_rect_l(object_t *object, int offset, int reset);
/**
 * @brief move object's rect to down side
 * @param object
 * @param offset
 * @param max
 */
void move_top_rect_d(object_t *object, int offset, int max);
/**
 * @brief move object's rect to upside
 * @param object
 * @param offset
 * @param max
 */
void move_top_rect_u(object_t *object, int offset, int reset);
/**
 * @brief set rectangle for player
 * @param player
 * @param dir
 */
void set_rect_player(player_t *player, int dir);
/**
 * @brief manege keys
 * @param game
 */
void manage_key(game_t *game);
/**
 * @brief save map in save file
 * @param game
 */
void save_map(game_t *game);
/**
 * @brief read save file to load player's stat
 * @param game
 */
void load_stat(game_t *game);
/**
 * @brief save stats in save file
 * @param nb_map
 * @param equipment
 * @param stat
 */
void save_stat(int nb_map, int *equipment, int *stat);
/**
 * @brief manage save option
 * @param game
 */
void manage_save(game_t *game);
/**
 * @brief init a new button
 * @return new button
 */
button_display_t *init_button(void);
/**
 * @brief manage start menu
 * @param game
 */
void manage_start_menu(game_t *game);
/**
 * @brief manage views
 * @param game
 */
void manage_view(game_t *game);
/**
 * @brief manage pause menu
 * @param game
 */
void manage_pause_menu(game_t *game);
/**
 * @brief change map
 * @param game
 */
void change_map(game_t *game);
/**
 * @brief manage map
 * @param game
 */
void manage_map(game_t *game);
/**
 * @brief load scene up
 * @param game
 */
void load_scene_up(game_t *game);
/**
 * @brief load scene down
 * @param game
 */
void load_scene_down(game_t *game);
/**
 * @brief manage cursor
 * @param window
 * @param clock
 * @param cursor
 * @param event
 */
void manage_cursor(sfRenderWindow *window, sfClock **clock,
    object_t *cursor, sfEvent event);
/**
 * @brief reset configuration files and save files
 * @return
 */
bool reset_file(void);
/**
 * @brief check flags for the game
 * @param arg
 * @return flags or not
 */
bool manage_flag(char *arg);
/**
 * @brief check if click append on object
 * @param event
 * @param window
 * @param obj
 * @return true or false
 */
bool click_on_obj(sfEvent event, sfRenderWindow *window, object_t obj);
/**
 * @brief manage fight
 * @param game
 */
void manage_fight(game_t *game);
/**
 * @brief load musics
 * @param game
 * @return fail or not
 */
bool create_music(game_t *game);
/**
 * @brief destroy all loaded objects
 * @param game
 */
void destroy_all(game_t *game);
/**
 * @brief get player's position
 * @param map
 * @return position
 */
sfVector2u get_pos_player(int **map);
/**
 * @brief manage end menu
 * @param game
 */
void manage_end_menu(game_t *game);
/**
 * @brief manage dialogs
 * @param game
 */
void manage_dialogue(game_t *game);
/**
 * @brief restart game
 * @param game
 * @return true or false
 */
bool restart_game(game_t *game);
/**
 * @brief check if a save file exist
 * @return true or false
 */
bool check_save(void);

#endif /* !MAIN_H_ */
