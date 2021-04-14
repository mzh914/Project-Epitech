/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** place_boats.c
*/

#include "navy.h"

int lim(char *file, int i)
{
    int j = 0;

    if (file[i] == 'A')
        j += 2;
    if (file[i] == 'B')
        j += 3;
    if (file[i] == 'C')
        j += 4;
    if (file[i] == 'D')
        j += 5;
    if (file[i] == 'E')
        j += 6;
    if (file[i] == 'F')
        j += 7;
    if (file[i] == 'G')
        j += 8;
    if (file[i] == 'H')
        j += 9;
    return j;
}

char **place_boat_1(char *filename)
{
    int i = 0;
    char **map = generate_map();
    char *file = open_file(filename);
    int lenght = file[0] - '0';

    for (i = 0; map[i][0] != file[3]; i++);
    i = i + lim(file, 2);
    map[i] = my_itoa(lenght);
    map[i][1] = ' ';

    for (i = 0; i != 88; i++)
        if (map[i][0] == file[6] && my_strcmp(map[i - 1], "\n") == 0)
            break;
    i = i + lim(file, 5);
    map[i] = my_itoa(lenght);
    if (my_strcmp(map[i + 1], "\n") != 0)
        map[i][1] = ' ';
    return map;
}

char **place_boat_2(char *filename)
{
    int i = 0;
    char **map = place_boat_1(filename);
    char *file = open_file(filename);
    int lenght = file[8] - '0';
    int count = 0;

    for (i = 0; map[i][0] != file[11]; i++);
    i = i + lim(file, 10);
    map[i] = my_itoa(lenght);
    map[i][1] = ' ';

    norm_boat_2(file, map, lenght, i);
    if (file[11] != file[14]) {
        for (int j = 0; j != lenght; j++) {
            map[i] = my_itoa(lenght);
            if (my_strcmp(map[i + 1], "\n") != 0)
                map[i][1] = ' ';
            i += 11;
        }
    }
    return map;
}

char **place_boat_3(char *filename)
{
    int i = 0;
    char **map = place_boat_2(filename);
    char *file = open_file(filename);
    int lenght = file[16] - '0';

    for (i = 0; map[i][0] != file[19]; i++);
    i = i + lim(file, 18);
    map[i] = my_itoa(lenght);
    map[i][1] = ' ';

    norm_boat_3(file, map, lenght, i);
    if (file[19] != file[22]) {
        for (int j = 0; j != lenght; j++) {
            map[i] = my_itoa(lenght);
            if (my_strcmp(map[i + 1], "\n") != 0)
                map[i][1] = ' ';
            i += 11;
        }
    }
    return map;
}

char **place_boat_4(char *filename)
{
    int i = 0;
    char **map = place_boat_3(filename);
    char *file = open_file(filename);
    int lenght = file[24] - '0';

    for (i = 0; map[i][0] != file[27]; i++);
    i = i + lim(file, 26);
    map[i] = my_itoa(lenght);
    map[i][1] = ' ';

    norm_boat_4(file, map, lenght, i);
    if (file[27] != file[30])
        for (int j = 0; j != lenght; j++) {
            map[i] = my_itoa(lenght);
            if (my_strcmp(map[i + 1], "\n") != 0)
                map[i][1] = ' ';
            i += 11;
        }
    return map;
}