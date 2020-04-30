/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_button
*/

#include <stdlib.h>
#include "game.h"
#include "main.h"
#include "pause_menu.h"
#include "start_menu.h"

static bool failed_button(button_display_t button)
{
    if (!button.font || !button.shape
        || !button.text)
        return (false);
    else
        return (true);
}

button_display_t *init_button(void)
{
    button_display_t *buttons = malloc(sizeof(button_display_t) * (nb_button));
    unsigned int i = 0;

    if (!buttons)
        return (NULL);
    for (unsigned int a = 0; a <= 3;a++, i++) {
        buttons[i] = create_button(pause_menu_buttons[a]);
        if (!failed_button(buttons[i]))
            return (NULL);
    }
    for (unsigned int a = 0; a <= 2;a++, i++) {
        buttons[i] = create_button(start_menu_buttons[a]);
        if (!failed_button(buttons[i]))
            return (NULL);
    }
    return (buttons);
}