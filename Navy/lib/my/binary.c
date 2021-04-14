/*
** EPITECH PROJECT, 2020
** B-PSU-100-PAR-1-4-myprintf-luka.boudjelal
** File description:
** binary.c
*/

#include "navy.h"

void binary_base(int nbr)
{
    char *binary_base = "01";
    my_convert_base(nbr, binary_base);
}