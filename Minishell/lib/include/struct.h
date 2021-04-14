/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** structures
*/

#ifndef STRUCT_H_
#define STRUCT_H_

struct my_printf_nb
{
    char c;
    long (*funct)(long);
};

struct my_printf_usnb
{
    char c;
    int base;
    char *(*funct)(long, long);
};

struct my_printf_char
{
    char c;
    int (*funct)(char *);
};

struct my_printf_waff
{
    char type;
    int base;
    char *(*funct)(long, long);
    char *prefix;
};

struct my_printf_flag
{
    char *type;
    int (*funct)(const char *, va_list, unsigned long *i);
};

#endif /* !STRUCT_H_ */
