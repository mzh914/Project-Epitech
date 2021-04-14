/*
** EPITECH PROJECT, 2020
** day04
** File description:
** function that returns a number, sent to the function
** as a string in the parameter
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

void counter(char const *str, long *i, long *count)
{
    while (str[*i] == '-' || str[*i] == '+') {
        if (str[*i] == '-')
            *count += 1;
        *i -= 1;
    }
}

long sign(char const *str)
{
    long count = 0;

    for (long i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= '0') && (str[i] <= '9')) {
            if (i > 0 && (str[i - 1] == '-')) {
                i--;
                counter(str, &i, &count);
                break;
            }
        }
    }
    if (count % 2 == 1)
        return (-1);
    else
        return 1;
}

char *nw_str(char const *str)
{
    long x = 0;
    char *new_str;

    new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (long i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= '1') && (str[i] <= '9')) {
            for (;str[i] >= '0' && str[i] <= '9'; i++) {
                new_str[x] = str[i];
                x++;
            }
            new_str[x] = '\0';
            break;
        }
    }
    return (new_str);
}

long none_nb_in_str(char const *str)
{
    for (long i = 0; str[i] != '\0'; i++)
        if (str[i] <= '9' && str[i] >= '0')
            return 0;
    return 1;
}

long  my_getnbr(char const *str)
{
    long res = 0;
    char *new_str;

    if (str[0] == '\0' || none_nb_in_str(str))
        return 0;
    new_str = nw_str(str);
    for (long i = 0; new_str[i] != '\0'; i++)
    {
        res = res + (new_str[i] - '0');
        if (new_str[i + 1] != '\0')
            res = res * 10;
    }
    res = res * sign(str);
    free(new_str);
    return (res);
}