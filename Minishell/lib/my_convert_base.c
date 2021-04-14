/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** base converter
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_revstr(char *str);

int how_much_for_malloc(int nb, int base)
{
    int x = 0;

    while (nb - base > 0) {
        nb = nb / base;
        x++;
    }
    return x + 2;
}

char *dec_to_base(long n, long base)
{
    long nb = n;
    char *res = malloc(sizeof(char) * (how_much_for_malloc(nb, base) + 1));
    long stock = 0;
    long x = 0;

    while (nb - base >= 0) {
        stock = (nb % base);
        if (base == 16 && stock > 9)
            stock = stock - 10 + 'a' - '0';
        res[x] = stock + '0';
        nb = nb / base;
        x++;
    }
    if (base == 16 && nb > 9)
        nb = nb - 10 + 'a' - '0';
    res[x] = nb + '0';
    res[x + 1] = '\0';
    return (my_revstr(res));
}

void p_case(void *str)
{
    my_putstr("0x");
    my_putstr(dec_to_base((long)&str, 16));
}

char *add_zero(char *str)
{
    char *new_res = malloc(sizeof(char) * 5);
    int x = 1;

    new_res[0] = '\\';
    while (x < 3) {
        new_res[x] = '0';
        x++;
    }
    my_strcat(new_res, str);
    new_res[4] = '\0';
    return new_res;
}

int s_case(char *str)
{
    char *res;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 32 && str[i] < 127)
            my_putchar(str[i]);
        else {
            res = malloc(sizeof(char) * how_much_for_malloc((int)str[i], 8));
            res = dec_to_base((long)str[i], 8);
            res = add_zero(res);
            my_putstr(res);
        }
    }
    free(res);
    return 1;
}