/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** place_boats_norm.c
*/

#include "navy.h"

void norm_boat_2(char *file, char **map, int lenght, int i)
{
    int count = 0;

    if (file[11] == file[14]) {
        count = (lim(file, 13) - lim(file, 10) + i);
        for (i += 1; i != count + 1; i++) {
            map[i] = my_itoa(lenght);
            if (my_strcmp(map[i + 1], "\n") != 0)
                map[i][1] = ' ';
        }
    }
}

void norm_boat_3(char *file, char **map, int lenght, int i)
{
    int count = 0;

    if (file[19] == file[22]) {
        count = (lim(file, 21) - lim(file, 18) + i);
        for (i += 1; i != count + 1; i++) {
            map[i] = my_itoa(lenght);
            if (my_strcmp(map[i + 1], "\n") != 0)
                map[i][1] = ' ';
        }
    }
}

void norm_boat_4(char *file, char **map, int lenght, int i)
{
    int count = 0;

    if (file[27] == file[30]) {
        count = (lim(file, 29) - lim(file, 26) + i);
        for (i += 1; i != count + 1; i++) {
            map[i] = my_itoa(lenght);
            if (my_strcmp(map[i + 1], "\n") != 0)
                map[i][1] = ' ';
        }
    }
}