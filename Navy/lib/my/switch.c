/*
** EPITECH PROJECT, 2020
** B-PSU-100-PAR-1-4-myprintf-luka.boudjelal
** File description:
** switch.c
*/

#include "navy.h"

void switch_1_norm(char *str, int i, va_list ap)
{
        switch(str[i]) {
            case 'c':
                my_putchar(va_arg(ap, int));
                break;
            case '%':
                my_putchar('%');
                break;
            case 's':
                my_putstr(va_arg(ap, char *));
                break;
            case 'd':
                my_put_nbr(va_arg(ap, int));
                break;
            case 'i':
                my_put_nbr(va_arg(ap, int));
                break;
            case 'b':
                binary_base(va_arg(ap, int));
                break;
        }
}

void switch_2_norm(char *str, int i, va_list ap)
{
    switch(str[i]) {
            case 'x':
                hexa(va_arg(ap, int));
                break;
            case 'X':
                hexa_base_maj(va_arg(ap, int));
                break;
            case 'u':
                my_put_nbr_unsigned(va_arg(ap, int));
                break;
            case 'o':
                octal_base(va_arg(ap, int));
                break;
            case '#':
                if (str[i + 1] == 'o') {
                    my_put_nbr(0);
                    octal_base(va_arg(ap, int));
                }
                break;
    }
}

void switch_3_norm(char *str, int i, va_list ap)
{
    switch(str[i]) {
        case '#':
            if (str[i + 1] == 'x') {
                my_putstr("0x");
                hexa(va_arg(ap, int));
            }
            if (str[i + 1] == 'X') {
                my_putstr("0X");
                hexa_base_maj(va_arg(ap, int));
            }
            break;
        case '+':
            if (str[i + 1] == 'd' || str[i + 1] == 'i') {
                my_putchar('+');
                my_put_nbr(va_arg(ap, int));
            }
            break;
    }
}

void switch_4_norm(char *str, int i, va_list ap)
{
    switch (str[i]) {
        case ' ':
            if ((str[i + 1] == 'd') || (str[i + 1] == 'i')) {
                my_putchar(' ');
                my_put_nbr(va_arg(ap, int));
            }
            break;
        case '.':
            if (str[i + 1] >= '0' && str[i - 1] <= '9')
                my_putstr_sp(va_arg(ap, char *));
            break;
        case 'l':
            if (str[i + 1] == 'd') {
                my_put_nbr_long(va_arg(ap, long));
            }
            break;
    }
}