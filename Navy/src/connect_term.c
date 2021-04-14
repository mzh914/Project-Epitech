/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** print.c
*/

#include "navy.h"

extern int gbl_var;

void connect_term_3(int pid)
{
    kill(pid, SIGUSR1);
}

void get_pid(int sig, siginfo_t *info, void *context)
{
    gbl_var = info->si_pid;
}

char **term1(int lim, char *filename)
{
    char **map = place_boat_4(filename);

    my_printf("waiting for enemy connection...\n\n");
    pause();
    my_printf("%s\n\nmy positions:\n", "enemy connected");
    my_printf("%s", " |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != lim; i++)
        my_printf("%s", map[i]);
    my_printf("\n%s\n", "enemy's positions:");
    my_printf("%s", " |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != lim; i++)
        my_printf("%s", generate_map()[i]);
    return map;
}

char **term2(int lim, char *filename)
{
    char **map = place_boat_4(filename);

    my_printf("successfully connected\n\nmy_positions:\n");
    my_printf("%s", " |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != lim; i++)
        my_printf("%s", map[i]);
    my_printf("\n%s\n", "enemy's positions:");
    my_printf("%s", " |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != lim; i++)
        my_printf("%s", generate_map()[i]);
    my_printf("\n%s\n", "waiting for enemy's attack...");
    return map;
}