/*
** EPITECH PROJECT, 2020
** B-CPE-100-PAR-1-4-cpoolday07-luka.boudjelal
** File description:
** my_putchar.c
*/

#include "navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}