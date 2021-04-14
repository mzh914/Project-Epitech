/*
** EPITECH PROJECT, 2020
** day_06
** File description:
** reproduce the behavior of the str.cmp function
*/

#include <stdio.h>
#include <string.h>

int my_strlen(char const *str);

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    for (; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++) {}
    return (s1[i] - s2[i]);
}