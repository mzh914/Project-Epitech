/*
** EPITECH PROJECT, 2020
** B-PSU-100-PAR-1-4-myprintf-luka.boudjelal
** File description:
** my_printf.c
*/

#include "navy.h"

int error(char *str, int i)
{
    if ((str[i] == 'o' && str[i - 1] == '#')
            || (str[i] == 'x' && str[i - 1] == '#') ||
            (str[i] == 'X' && str[i - 1] == '#') ||
            (str[i] == 'd' && str[i - 1] == '+') ||
            (str[i] == 'i' && str[i - 1] == '+') ||
            (str[i] == 'd' && str[i - 1] == ' ') ||
            (str[i] == 'i' && str[i - 1] == ' ') ||
            (str[i] == 'd' && str[i - 1] == 'l'))
                return 1;
    return 0;
}

void norm_fin(char *str, int i, va_list ap)
{
    switch_1_norm(str, i, ap);
    switch_2_norm(str, i, ap);
    switch_3_norm(str, i, ap);
    switch_4_norm(str, i, ap);
}

int my_printf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '%') {
            if (error(str, i) == 1)
                i++;
            else if (str[i - 1] == '.' && str[i + 1] == 's')
                i += 2;
            if (str[i - 1] == '.' && str[i + 2] == 's')
                i += 3;
        my_putchar(str[i]);
        }
        else {
            i++;
            norm_fin(str, i, ap);
        }
    }
    return 0;
}