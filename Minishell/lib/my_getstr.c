/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** convert an int into a str
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_getstr(long nb)
{
    char *res;
    long size = 1;
    long x = 0;

    for (long i = 10; (nb / i) != 0; i = i * 10)
        size++;
    res = malloc(sizeof(char) * size);
    for (long i = 1; (nb / i) != 0; i = i * 10) {
        res[x] = ((nb / i) % 10) + '0';
        x++;
    }
    res[x] = '\0';
    return my_revstr(res);
}