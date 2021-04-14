/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** myshell
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "minshell.h"

int in_bin(char *command)
{
    DIR *dir = opendir("/bin/");
    struct dirent *read_dir;

    if (dir == NULL)
        exit(84);
    while ((read_dir = readdir(dir)) != NULL)
        if (my_strcmp(read_dir->d_name, command) == 0)
            return 1;
    return 0;
}

void execute_command(char *str, char **env)
{
    char **command;

    phrase_it(str);
    command  = transfo(str);
    if (str[0] == '\0')
        return ;
    if (my_strcmp(command[0], "setenv") == 0 || \
        my_strcmp(command[0], "unsetenv") == 0) {
        env_setting(command);
        return ;
    }
    if (my_strcmp(command[0], "cd") == 0) {
        change_directory(command, str, env);
    } else if (in_bin(command[0]))
        execu_bin(str, env);
    else
        execu(str, env);
}

void terminal_loop(char **env)
{
    char *str = NULL;
    size_t len = 0;
    int loop = 1;
    int err = 0;

    while (loop) {
        my_printf("$> ");
        err = getline(&str, &len, stdin);
        if (err <= 0) {
            my_printf("\n");
            exit(0);
        } else {
            str[my_strlen(str) - 1] = '\0';
            execute_command(str, env);
        }
    }
}