/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** create_menu
*/

#include "my.h"
#include "button.h"

static void create_menu_background(char *path, sfRenderWindow *window)
{
    sfTexture *menu_bg_texture = sfTexture_createFromFile(path, NULL);
    sfSprite *menu_bg_sprite = sfSprite_create();

    sfSprite_setTexture(menu_bg_sprite, menu_bg_texture, sfFalse);
    sfRenderWindow_drawSprite(window, menu_bg_sprite, NULL);
}

void create_menu(sfRenderWindow *window, int nb_buttons, button_t const *button,
                char *path)
{
    create_menu_background(path, window);
    for (int i = 0; i != nb_buttons; i++) {
        create_button(button[i], window);
    }
}