/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** error_boats.c
*/

#include "navy.h"

int error_lenght_boats_1(char *filename)
{
    char *file = open_file(filename);
    int tmp = 0;

    if (file[3] == file[6]) {
        tmp = (lim(file, 5) - '0') - (lim(file, 2) - '0') + 1;
        if (tmp != (file[0]) - '0')
            return 0;
    }
    if (file[2] == file[5]) {
        tmp = (file[6] - '0') - (file[3] - '0') + 1;
        if (tmp != (file[0] - '0'))
            return 0;
    }
    return 1;
}

int error_lenght_boats_2(char *filename)
{
    char *file = open_file(filename);
    int tmp = 0;

    if (file[11] == file[14]) {
        tmp = (lim(file, 13) - '0') - (lim(file, 10) - '0') + 1;
        if (tmp != (file[8]) - '0')
            return 0;
    }
    if (file[10] == file[13]) {
        tmp = (file[14] - '0') - (file[11] - '0') + 1;
        if (tmp != (file[8] - '0'))
            return 0;
    }
    return 1;
}

int error_lenght_boats_3(char *filename)
{
    char *file = open_file(filename);
    int tmp = 0;

    if (file[19] == file[22]) {
        tmp = (lim(file, 21) - '0') - (lim(file, 18) - '0') + 1;
        if (tmp != (file[16]) - '0')
            return 0;
    }
    if (file[18] == file[21]) {
        tmp = (file[22] - '0') - (file[19] - '0') + 1;
        if (tmp != (file[16] - '0'))
            return 0;
    }
    return 1;
}

int error_lenght_boats_4(char *filename)
{
    char *file = open_file(filename);
    int tmp = 0;

    if (file[27] == file[30]) {
        tmp = (lim(file, 29) - '0') - (lim(file, 26) - '0') + 1;
        if (tmp != (file[24]) - '0')
            return 0;
    }
    if (file[26] == file[29]) {
        tmp = (file[30] - '0') - (file[27] - '0') + 1;
        if (tmp != (file[24] - '0'))
            return 0;
    }
    return 1;
}

int error_lenght(char *filename)
{
    if (error_lenght_boats_1(filename) == 0 || error_lenght_boats_2(filename)
    == 0 || error_lenght_boats_3(filename) == 0 ||
    error_lenght_boats_4(filename) == 0) {
        my_printf("bad boat lenght\n");
        return 84;
    }
    return 0;
}