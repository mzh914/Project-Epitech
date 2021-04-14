/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** signal_norm.c
*/

#include "navy.h"

extern int gbl_var;

struct data_sig {
    char letter;
    int col;
};

/*char **enemi_pos(void)
{
    char **map = generate_map();
    char *str = get_coor();
    int i = 0;

    for (i = 0; map[i][0] != str[1] &&
    my_strcmp(map[i - 1], "\n") == 0; i++);
    i += lim_c(str[0]);
    return map;
}*/

    //while (error_input(coor) != 1);
char *send_data(pid_t pid, int sig)
{
    char *coor = get_coor();
    int pos = coor[1] - '0';
    struct data_sig nb_col[] = {{'A', 10}, {'B', 20}, {'C', 30}, {'D', 40}, \
    {'E', 50}, {'F', 60}, {'G', 70}, {'H', 80}};

    for (int i = 0; i < 8; i++)
        if (nb_col[i].letter == coor[0]) {
            pos += nb_col[i].col;
            break;
        }
    for (int i = 0; i < pos; i++) {
        kill(pid, sig);
        usleep(300);
    }
    return coor;
}

void caught_data(int sig, siginfo_t *info, void *ucontext)
{
    gbl_var += 1;
}

void norm_signal(int sig)
{
    struct sigaction my_sig;

    my_sig.sa_sigaction = &caught_data;
    my_sig.sa_flags = SA_SIGINFO;

    sigaction(sig, &my_sig, NULL);
    pause();
    for (int i = 0; i < 90; i++) {
        sigaction(sig, &my_sig, NULL);
        usleep(300);
    }
}

char *catch_data(int sig)
{
    struct data_sig nb_col[] = {{'A', 10}, {'B', 20}, {'C', 30}, {'D', 40}, \
    {'E', 50}, {'F', 60}, {'G', 70}, {'H', 80}};
    int row;
    char *res = malloc(sizeof(char) * 3);
    gbl_var = 0;

    norm_signal(sig);
    row = gbl_var % 10;
    for (int i = 0; i < 8; i++)
        if (nb_col[i].col == gbl_var - row)
            res[0] = nb_col[i].letter;
    res[1] = row + '0';
    res[2] = '\0';
    return res;
}