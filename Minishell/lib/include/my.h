/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int char_case(const char *str, va_list ap, unsigned long *i);

char *my_getstr(long nb);

char *my_strcat(char *dest, char const *src);

char *my_revstr(char *str);

void my_putchar(char c);

char *dec_to_base(long n, long base);

int how_much_for_malloc(int nb, int base);

long my_put_nbr(long nb);

int write(int fd, char *Buff, int NumBytes);

int my_strlen(char const *str);

int my_putstr(char *str);

int my_printf(const char *format, ...);

int numeric_case(const char *str, va_list ap, unsigned long *i);

int s_case(char *str);

char *xconvrter(long n, long base);

char *my_strcpy(char *dest, char const *src);

void p_case(void *str);

long how_much_to_add(const char *str, long to_add, unsigned long *i);

long  my_getnbr(char const *str);

int zf_nb_case(char c, va_list ap, long to_add, char c_case);

int zf_other_case(char c, va_list ap, long to_add, char c_case);

int zf_char_case(char c, va_list ap, long to_add, char c_case);

int zero_flag(const char *str, va_list ap, unsigned long *i);

int waffle_flag(const char *str, va_list ap, unsigned long *i);

int minus_flag(const char *str, va_list ap, unsigned long *i);

char *xc(char *str);

#endif