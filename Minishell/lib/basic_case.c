/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** basic case
*/

#include "my.h"
#include "struct.h"

const struct my_printf_nb sign_int[] = {{'d', &my_put_nbr}, \
    {'i', &my_put_nbr}};

const struct my_printf_usnb uns_fct[] = {{'o', 8, &dec_to_base}, \
    {'u', 10, &dec_to_base}, {'x', 16, &dec_to_base}, {'X', 16, &dec_to_base}, \
    {'b', 2, &dec_to_base}};

const struct my_printf_char c_fct[] = {{'s', &my_putstr}, {'S', &s_case}};

char *xc(char *str)
{
    for (int x = 0; str[x] != '\0'; x++)
        if (str[x] >= 'a' && str[x] <= 'z')
            str[x] = str[x] - 32;
    return str;
}

char *xconvrter(long n, long base)
{
    long nb = n;
    char *res = malloc(sizeof(char) * how_much_for_malloc(nb, base));
    long stock = 0;
    long x = 0;

    while (nb - base > 0) {
        stock = (nb % base);
        if (base == 16 && stock > 9)
            stock = stock - 10 + 'A' - '0';
        res[x] = stock + '0';
        nb = nb / base;
        x++;
    }
    if (base == 16 && nb > 9)
        nb = nb - 10 + 'A' - '0';
    res[x] = nb + '0';
    return (my_revstr(res));
}

int numeric_case(const char *str, va_list ap, unsigned long *i)
{
    char c = str[*i];
    char *(*ufct)(long, long);

    for (int x = 0; x < 2; x++)
        if (sign_int[x].c == c) {
            if (str[*i - 1] == ' ')
                my_putchar(' ');
            my_put_nbr((long)va_arg(ap, int));
            return 1;
        }
    for (int x = 0; x < 5; x++)
        if (uns_fct[x].c == c) {
            ufct = uns_fct[3].funct;
            if (c == 'X')
                my_putstr(xc(ufct(va_arg(ap, unsigned int), uns_fct[x].base)));
            else
                my_putstr(ufct(va_arg(ap, unsigned int), uns_fct[x].base));
            return 1;
        }
    return 0;
}

int char_case(const char *str, va_list ap, unsigned long *i)
{
    char c = str[*i];
    int (*display)(char *);

    for (int x = 0; x < 2; x++)
        if (c_fct[x].c == c) {
            display = c_fct[x].funct;
            display(va_arg(ap, char *));
            return 1;
        }
    if (c == 'c')
        my_putchar((char)va_arg(ap, int));
    else if (c == 'p')
        p_case(va_arg(ap, void *));
    else if (c == '%')
        my_putchar('%');
    else
        return 0;
    return 1;
}
