/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** item
*/

#ifndef ITEM_H_
#define ITEM_H_

#include "game.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdbool.h>

typedef struct item{
    object_t object;
    char *name;
    unsigned int quantity;
    char *description;
    bool equipable;
    bool usable;
}item_t;

#endif /* !ITEM_H_ */
