/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "game.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdbool.h>

typedef struct item{
    char *name;
    unsigned int quantity;
    char *description;
    bool equipable;
    bool usable;
}item_t;

#endif /* !INVENTORY_H_ */
