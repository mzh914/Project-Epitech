/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** line_formating
*/

#include <minshell.h>

void move_n(char *av, int *i)
{
    for (int j = *i; av[j] != '\0'; j++)
        av[j] = av[j + 1];
    *i -= 1;
}

void phrase_it(char *av)
{
    for (int i = 0; av[i] != '\0'; i++) {
        increment_i(&i, av);
        if (av[i + 1] != '\0' && av[i] == ' ' && \
            (av[i + 1] == ' ' || av[i + 1] < 32))
            move_n(av, &i);
        if (av[i] < 32) {
            av[i] = ' ';
            i--;
        }
        if (av[i] == ' ' && (i == 0 || av[i + 1] == '\0'))
            move_n(av, &i);
    }
}
