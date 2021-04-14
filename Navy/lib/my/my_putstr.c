/*
** EPITECH PROJECT, 2020
** d3
** File description:
** my_putstr
*/

#include "navy.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

void my_putstr_sp(char const *str)
{
    int nbr;
    int i;
    int j = 0;
    char *tmp = malloc(sizeof(char *) * 3);

    for (i = 0; (str[i] != '.'); i++);
    if ((str[i + 1] >= '0' && str[i + 1] <= '9') &&
    (str[i + 2] >= '0' && str[i + 2] <= '9')) {
        tmp[j] = str[i + 1];
        tmp[j + 1] = str[i + 2];
        nbr = my_getnbr(tmp);
    }
    if (str[i + 2] == 's' && str[i + 1] >= '0' && str[i + 1] <= '9') {
        nbr = CTOI(str[i + 1]);
    }

    for (int i = 0; i != nbr && (str[i] != '\0'); i++) {
        my_putchar(str[i]);
    }
}