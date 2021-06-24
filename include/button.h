/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdbool.h>
/**
 * @brief different types of buttons
 * @enum button_type
 * 
 */
enum button_type {
    P_RESUME,
    P_MAIN_MENU,
    P_SAVE,
    P_QUIT,
    D_RESTART,
    D_QUIT,
    S_START,
    S_HTP,
    S_QUIT,
};
/**
 * @struct button
 * @typedef button_t
 * @brief info about a button
 *
 */
typedef struct button {
    sfVector2f position;
    sfVector2f size;
    sfColor color;
    sfIntRect rect;
    unsigned int character_size;
    char *font_pathfile;
    char *text;
} button_t;
/**
 * @struct button_display
 * @typedef button_display_t
 * @brief info needed to display a button
 */
typedef struct button_display {
    sfRectangleShape *shape;
    sfIntRect rect;
    sfText *text;
    sfFont *font;
} button_display_t;
/**
 * @brief create a new button
 * @param button_to_create
 * @return new button
 */
button_display_t create_button(button_t button_to_create);

#endif /* !BUTTON_H_ */
