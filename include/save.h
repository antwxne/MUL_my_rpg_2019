/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save
*/

#ifndef SAVE_H_
#define SAVE_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static const int rights = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;

static const char *fp_map[] = {
    ".config/maps/map_1",
    ".config/maps/map_2"
};

#endif /* !SAVE_H_ */
