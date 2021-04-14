/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** octal_base.c
*/

#include "navy.h"

int octal_base(int nbr)
{
    char *octal_base = "01234567";
    my_convert_base(nbr, octal_base);
    return 0;
}