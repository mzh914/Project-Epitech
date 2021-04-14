/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_itoa.c
*/

#include "navy.h"

char *my_itoa(int n)
{
    char *s = malloc(sizeof(char *) * n + 1);
    int i = 0;

    if (n == 0)
        s[i] = '0';
    for (i = 0; n != 0; i++) {
        s[i] = (n % 10) + '0';
        n /= 10;
    }
    s[i] = '\0';
    return my_revstr(s);
}