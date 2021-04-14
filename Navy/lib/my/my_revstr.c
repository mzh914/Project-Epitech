/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** my_revstr.c
*/

#include "navy.h"

char *my_revstr(char *str)
{
    int j = my_strlen(str) - 1;
    char tmp;

    for (int i = 0; i < j; i++) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j--;
    }
    return (str);
}