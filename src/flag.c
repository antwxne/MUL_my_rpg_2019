/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** flag
*/

#include "main.h"
#include "my.h"

static const char *help[] = {
    "\033[1;96m****************************\033[1;91;4;5mMy_Rpg\033[1;25;24;96m****************************\n",
    "*                                                            *\n",
    "*                     \033[0mWelcome to our Rpg!\033[1;96m                    *\n",
    "*                                                            *\n",
    "*              \033[0mTo launch the game run \033[1;92m./my_rpg\033[1;96m               *\n",
    "*                                                            *\n",
    "*                 \033[0mYou can use the flag \033[1m--reset\033[1;96m               *\n",
    "*                      \033[0mto reset the game\033[1;96m                     *\n",
    "*                                                            *\n",
    "**************************************************************\n\033[0m",
    NULL
};

static bool display_help(void)
{
    for (unsigned int i = 0; help[i] != NULL; i++)
        my_putstr((char *) help[i]);
    return (true);
}

bool manage_flag(char *arg)
{
    if (my_strcmp(arg, "--reset") == 0)
        return (reset_file());
    if (my_strcmp(arg, "-h") == 0 || my_strcmp(arg, "--help") == 0)
        return (display_help());
    my_putstr("Unknow option. Please run with -h\n");
    return (false);
}
