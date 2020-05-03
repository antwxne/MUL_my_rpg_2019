/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_revstr(char *str);

char *my_itoa(int nb)
{
    char *dest = malloc(sizeof(char) * 12);
    int i = 0;
    int bool = 0;

    if (!dest)
        return (NULL);
    if (nb == 0) {
        dest[i] = '0';
        i++;
    }
    bool = nb < 0 ? 1 : 0;
    for (; nb != 0; i++, nb /= 10)
        dest[i] = (nb%10)+'0';
    if (bool == 1) {
        dest[i] = '-';
        i += 1;
    }
    dest[i] = '\0';
    return (my_revstr(dest));
}