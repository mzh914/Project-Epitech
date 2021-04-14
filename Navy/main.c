/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** main.c
*/

#include "navy.h"

int gbl_var = 0;

int main(int ac, char **av)
{
    if (call_error_gestion(av, ac) == 84 || (ac != 2 && ac != 3))
        return 84;
    pid_t pid_process2 = getpid();
    struct sigaction sa;
    char **map;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &get_pid;
    my_printf("%s%d\n", "my_pid: ",  pid_process2);
    if (ac == 3) {
        connect_term_3(my_getnbr(av[1]));
        if (gameloop_p2(my_getnbr(av[1]), term2(88, av[2])))
            my_printf("I won\n");
    }
    if (ac == 2) {
        sigaction(SIGUSR1, &sa, NULL);
        map = term1(88, av[1]);
        pid_process2 = gbl_var;
        if (gameloop_p1(pid_process2, map))
            my_printf("I won\n");
    }
    return 0;
}