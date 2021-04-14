/*
** EPITECH PROJECT, 2020
** B-PSU-100-PAR-1-4-myprintf-luka.boudjelal
** File description:
** my_putnbr_base.c
*/

#include "navy.h"

int my_convert_base(unsigned int nbr, char *base)
{
    unsigned int base_lenght = my_strlen(base);

    if (nbr == 0)
        return (0);

    my_convert_base(nbr / base_lenght, base);
    my_putchar(base[nbr % base_lenght]);
    return (0);
}