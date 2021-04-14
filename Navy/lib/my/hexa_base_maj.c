/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** hexa_base_maj.c
*/

#include "navy.h"

void hexa_base_maj(int nbr)
{
    char *hexa_base_maj = "0123456789ABCDEF";
    my_convert_base(nbr, hexa_base_maj);
}