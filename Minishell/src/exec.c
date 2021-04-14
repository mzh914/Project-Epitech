/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** exec
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minshell.h"

char *cpy_command(char *str)
{
    char *command = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (command == NULL)
        exit(84);
    my_strcpy(command, str);
    return command;
}

void delete_char_to_i(char *str, int i)
{
    for (int j = 0; j < i; j++)
        for (int k = 0; str[k] != '\0'; k++)
            str[k] = str[k + 1];
    if (str[0] == ' ')
        for (int k = 0; str[k] != '\0'; k++)
            str[k] = str[k + 1];
}

char **transfo(char *str)
{
    int count = count_pointer(str);
    char **command_arr = malloc(sizeof(char *) * (count + 1));
    char *command = cpy_command(str);
    int i = 0;

    count = 0;
    for (i = 0; command[0] != '\0'; i = 0) {
        increment_i(&i, command);
        command_arr[count] = malloc(sizeof(char) * (i + 1));
        if (command_arr[count] == NULL)
            exit(84);
        my_strncpy(command_arr[count], command, i);
        count++;
        delete_char_to_i(command, i);
    }
    return command_arr;
}

void execu_bin(char *str, char **env)
{
    env_t process = get_env(str);
    char *command = malloc(sizeof(char) * (my_strlen(process.path[0] + 6)));
    int time = 1;

    if (command == NULL)
        exit(84);
    my_strcpy(command, "/bin/");
    my_strcat(command, process.path[0]);
    process.cpid = fork();
    if (process.cpid == 0) {
        process.status = execve(command, process.path, env);
    }
    wait(&time);
    if (process.status == -1)
        my_printf("Segmentation fault\n");
}

void execu(char *str, char **env)
{
    env_t process = get_env(str);
    int time = 1;

    process.cpid = fork();
    if (process.cpid == 0) {
        process.status = execve(str, process.path, env);
    }
    wait(&time);
    if (process.status == -1) {
        my_printf("No such file or program segfaulted\n");
    }
}