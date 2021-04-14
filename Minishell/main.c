/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "minshell.h"

int main(int ac, char **av, char **env)
{
    error_handler(ac);
    terminal_loop(env);
    return 0;
}