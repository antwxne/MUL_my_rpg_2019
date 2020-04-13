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

typedef struct button{
    sfVector2f position;
    sfVector2f size;
    sfColor color;
    sfIntRect rect;
    unsigned int character_size;
    char *font_pathfile;
    char *text;
}button_t;

void create_button(button_t button_to_create, sfRenderWindow *window);

#endif /* !BUTTON_H_ */
