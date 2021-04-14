/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** flag manager
*/

#include "my.h"
#include "struct.h"

const struct my_printf_waff us_funct[] = {{'o', 8, &dec_to_base, "0"}, \
    {'x', 16, &dec_to_base, "0x"}, {'X', 16, &xconvrter, "0X"}, {'u', 10, \
    dec_to_base, ""}, {'b', 2, &dec_to_base, "0b"}};

int minus_flag(const char *str, va_list ap, unsigned long *i)
{
    long to_add = 0;

    *i = *i + 1;
    if (str[*i] == '0') {
        *i = *i + 1;
        to_add = how_much_to_add(str, to_add, i);
        if (zf_nb_case(str[*i], ap, to_add, '-'))
            return 1;
        if (zf_char_case(str[*i], ap, to_add, '-'))
            return 1;
    }
    if (str[*i] >= '1' && str[*i] <= '9') {
        *i = *i + 1;
        to_add = how_much_to_add(str, to_add, i);
        if (zf_nb_case(str[*i], ap, to_add, '-'))
            return 1;
        if (zf_char_case(str[*i], ap, to_add, '-'))
            return 1;
    }
    return 0;
}

int zero_flag(const char *str, va_list ap, unsigned long *i)
{
    long to_add = 0;

    if (str[*i] == '0') {
        *i = *i + 1;
        to_add = how_much_to_add(str, to_add, i);
        if (zf_nb_case(str[*i], ap, to_add, '0'))
            return 1;
        if (zf_char_case(str[*i], ap, to_add, ' '))
            return 1;
    }
    if (str[*i] >= '1' && str[*i] <= '9') {
        to_add = how_much_to_add(str, to_add, i);
        if (zf_nb_case(str[*i], ap, to_add, ' '))
            return 1;
        if (zf_char_case(str[*i], ap, to_add, ' '))
            return 1;
    }
    return 0;
}

int waffle_extra(const char *str, va_list ap, unsigned long *i)
{
    char *(*fct)(long, long);
    char *res;
    char *prefix = malloc(sizeof(char) * 3);
    int j = *i;

    while (str[j] >= '0' && str[j] <= '9')
        j++;
    for (int x = 0; x < 5; x++)
        if (us_funct[x].type == str[j]) {
            fct = us_funct[x].funct;
            prefix = us_funct[x].prefix;
            res = fct((long)va_arg(ap, unsigned int), us_funct[x].base);
            if (*res != '0')
                my_putstr(prefix);
            return 1;
        }
    return 0;
}

int waffle_flag(const char *str, va_list ap, unsigned long *i)
{
    char *(*fct)(long, long);
    char *res;
    char *prefix = malloc(sizeof(char) * 3);

    *i = *i + 1;
    for (int x = 0; x < 5; x++)
        if (us_funct[x].type == str[*i]) {
            fct = us_funct[x].funct;
            prefix = us_funct[x].prefix;
            res = fct((long)va_arg(ap, unsigned int), us_funct[x].base);
            if (*res != '0')
                my_putstr(prefix);
            my_putstr(res);
            return 1;
        }
    return 0;
}