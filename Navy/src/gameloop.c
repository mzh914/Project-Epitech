/*
** EPITECH PROJECT, 2020
** navy
** File description:
** gameloop
*/

#include "navy.h"

extern int gbl_var;

void game_ender(int sig)
{
    gbl_var = 1;
}

    //while (error_input() != 1);
void attack(int pid_to_kill, int sig, char **enemy_map, char **map)
{
    struct sigaction my_sig;

    my_sig.sa_sigaction = &caught_data;
    my_sig.sa_flags = SA_SIGINFO;
    send_data(pid_to_kill, sig);
    gbl_var = 0;
    if (sig == 12)
        sig = 10;
    else
        sig = 12;
    sigaction(sig, &my_sig, NULL);
    for (int i = 0; i < 4; i++) {
        if (i == 0)
            usleep(300);
        sigaction(sig, &my_sig, NULL);
        usleep(300);
    }
    if (gbl_var == 2)
        my_printf("hit\n");
    else
        my_printf("missed\n");
    display_eot(map, enemy_map);
}

void defend(int pid, int sig, char **map)
{
    char *data = malloc(sizeof(char) * 3);
    
    data = catch_data(sig);
    my_printf("%s: ", data);
    is_there_a_boat(map, data, pid, sig);
}

int gameloop_p1(int processid2, char **map)
{
    int play = 1;
    char **enemy_map = generate_map();
    struct sigaction sig;

    sig.sa_sigaction = &game_ender;
    for (int i = 0; play; i++)
    {
        if (i % 2 == 0)
            attack(processid2, SIGUSR2, enemy_map, map);
        else
            defend(processid2, SIGUSR1, map);
        if (boat_down(map))
            break;
        gbl_var = 0;
        sigaction(SIGUSR2, &sig, NULL);
        if (gbl_var == 1)
            return 1;
    }
    kill(processid2, SIGUSR2);
    my_printf("Enemy won\n");
    return 0;
}

int gameloop_p2(int processid1, char **map)
{
    int play = 1;
    char **enemy_map = generate_map();
    struct sigaction sig;

    sig.sa_sigaction = &game_ender;
    for (int i = 0; play; i++)
    {
        if (i % 2 == 0)
            defend(processid1, SIGUSR2, map);
        else
            attack(processid1, SIGUSR1, enemy_map, map);
        if (boat_down(map))
            break;
        gbl_var = 0;
        sigaction(SIGUSR1, &sig, NULL);
        if (gbl_var == 1)
            return 1;
    }
    kill(processid1, SIGUSR1);
    my_printf("Enemy won\n");
    return 0;
}