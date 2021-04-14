/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include "struct.h"

struct my_printf_flag flag[] = {{"#", &waffle_flag}, {"0123456789", \
    &zero_flag}, {"-", &minus_flag}, {"dibouxX", &numeric_case}\
    , {"sScp%", &char_case}};

int space_skipper(const char *c, int i)
{
    while (c[i] == ' ')
        i = i + 1;
    return i;
}

int case_finder(const char *format, va_list ap, unsigned long *i)
{
    int (*funct)(const char *, va_list, unsigned long *i);

    for (int j = 0; j < 5; j++)
        for (int k = 0; flag[j].type[k] != '\0'; k++) {
            if (format[*i] == flag[j].type[k]) {
                funct = flag[j].funct;
                funct(format, ap, i);
                return 1;
            }
        }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int return_value = 0;

    va_start(ap, format);
    for (unsigned long i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        else if (format[i] == '%') {
            i++;
            if (format[i] == ' ')
                i = space_skipper(format, i);
            return_value++;
            if (!case_finder(format, ap, &i)) {
                my_putchar('%');
                my_putchar(format[i]);
            }
        }
    }
    va_end(ap);
    return return_value;
}
