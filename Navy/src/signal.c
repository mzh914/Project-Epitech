/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** signal.c
*/

#include "navy.h"

extern int gbl_var;

struct data_sig {
    char letter;
    int col;
};

char *get_coor(void)
{
    size_t size = 0;
    char *str;

    my_printf("\nattack: ");
    getline(&str, &size, stdin); 
    if (str[1] == '0' || my_strlen(str) > 3 || str[0] < 'A' || str[0] > 'H') {
        my_printf("wrong position");
        return get_coor();
    } else
        str[2] = '\0';
    my_printf("%s: ", str);
    return str;
}

int lim_c(char c)
{
    int j = 0;

    if (c == 'A')
        j += 2;
    if (c == 'B')
        j += 3;
    if (c == 'C')
        j += 4;
    if (c == 'D')
        j += 5;
    if (c == 'E')
        j += 6;
    if (c == 'F')
        j += 7;
    if (c == 'G')
        j += 8;
    if (c == 'H')
        j += 9;
    return j;
}

int map_my_pos(char *coor)
{
    int i = 0;
    struct data_sig nb_col[] = {{'A', 10}, {'B', 20}, {'C', 30}, {'D', 40}, \
    {'E', 50}, {'F', 60}, {'G', 70}, {'H', 80}};

    for (i = 0; i < 8; i++)
        if (nb_col[i].letter == coor[0]) {
            i += nb_col[i].col;
            break;
        }
    i += coor[1] - '0';
    return i;
}
