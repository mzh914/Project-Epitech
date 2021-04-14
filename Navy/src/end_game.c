/*
** EPITECH PROJECT, 2020
** navy
** File description:
** end_game
*/

#include "navy.h"

struct data_sig {
    char letter;
    int col;
};

void display_eot(char **map, char **ennemy_map)
{
    my_printf("%s", " |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != 88; i++)
        my_printf("%s", map[i]);
    my_printf("\n%s\n", "enemy's positions:");
    my_printf("%s", " |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != 88; i++)
        my_printf("%s", ennemy_map[i]);
    my_printf("waiting for enemy's attack...\n");
}

int boat_down(char **map)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (map[i][j] > '0' && map[i][j] <= '9')
                return 0;
    return 1;
}

int is_there_a_boat(char **map, char *coor, int pid, int sig)
{
    int pos = map_my_pos(coor);

    if (map[pos / 10][pos % 10] > '0' && \
     map[pos / 10][pos % 10] <= '9') {
        map[pos / 10][pos % 10 + 2] = 'x';
        kill(pid, sig);
        usleep(300);
        kill(pid, sig);
        my_printf("hit\n");
        return 1;
    }
    map[pos / 10][pos % 10] = 'x';
    my_printf("missed\n");
    return 0;
}