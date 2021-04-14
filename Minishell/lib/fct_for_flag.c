/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** fonction for flag characters
*/

#include "my.h"
#include "struct.h"

const struct my_printf_waff uns_funct[] = {{'o', 8, &dec_to_base, "0"}, \
    {'x', 16, &dec_to_base, "0x"}, {'X', 16, &xconvrter, "0X"}, {'u', 10, \
    dec_to_base, ""}, {'b', 2, &dec_to_base, "0b"}};

const struct my_printf_char ch_fct[] = {{'s', &my_putstr}, {'S', &s_case}};

long how_much_to_add(const char *str, long to_add, unsigned long *i)
{
    char *res;

    for (int y = *i; str[y] >= '0' && str[y] <= '9'; to_add++)
            y++;
        res = malloc(sizeof(char) * to_add);
        to_add = 0;
        for (; str[*i] >= '0' && str[*i] <= '9'; *i = *i + 1) {
            res[to_add] = str[*i];
            to_add++;
        }
    return my_getnbr(res);
}

char *add_char(char *nb, long to_add, char c_case)
{
    char *res = malloc(sizeof(char) * (to_add + 1 + my_strlen(nb)));
    char *cpy = malloc(sizeof(char) * (to_add + 1 + my_strlen(nb)));
    if (to_add <= 0) {
        return nb;
    }
    if (c_case == '-') {
        my_strcpy(cpy, nb);
        for (long x = 0; x < to_add; x++)
            res[x] = ' ';
        my_strcat(cpy, res);
        return cpy;
    }
    for (long x = 0; x < to_add; x++) {
        res[x] = c_case;
    }
    my_strcat(res, nb);
    return res;
}

int zf_nb_case(char c, va_list ap, long to_add, char c_case)
{
    char *(*fct)(long, long);

    if (c == 'd' || c == 'i') {
        char *nb = my_getstr((long)va_arg(ap, int));
        to_add = to_add - my_strlen(nb);
        my_putstr(add_char(nb, to_add, c_case));
        return 1;
    }
    for (int j = 0; j < 5; j++)
        if (c == uns_funct[j].type) {
            fct = uns_funct[j].funct;
            char *nb = fct((long)va_arg(ap, unsigned int), uns_funct[j].base);
            to_add = to_add - my_strlen(nb);
            my_putstr(add_char(nb, to_add, c_case));
            return 1;
        }
    return 0;
}

int zf_other_case(char c, va_list ap, long to_add, char c_case)
{
    if (c == 'p') {
        void *ptr = va_arg(ap, void *);
        to_add = to_add - my_strlen(my_getstr((long)&ptr));
        if (c_case == '-')
            p_case(ptr);
        for (int j = 0; j < to_add; j++)
            my_putchar(' ');
        if (c_case == ' ')
            p_case(ptr);
        return 1;
    }
    if (c == 'c') {
        if (c_case == '-')
            my_putchar(va_arg(ap, int));
        for (int j = 1; j < to_add; j++)
            my_putchar(' ');
        if (c_case == ' ')
            my_putchar(va_arg(ap, int));
        return 1;
    }
    return 0;
}

int zf_char_case(char c, va_list ap, long to_add, char c_case)
{
    for (int x = 0; x < 2; x++)
        if (ch_fct[x].c == c) {
            char *str = va_arg(ap, char *);
            to_add = to_add - my_strlen(str);
            my_putstr(add_char(str, to_add, c_case));
            return 1;
        }
    if (zf_other_case(c, ap, to_add, c_case))
        return 1;
    return 0;
}
