/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** utility
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "minshell.h"

void error_handler(int ac)
{
    if (ac != 1)
        exit(84);
}

int count_pointer(char *str)
{
    int count = 1;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '"')
            for (i += 1; str[i] != '"'; i++);
        else if (str[i] == ' ')
            count++;
    return count;

}

void increment_i(int *i, char *command)
{
    if (command[*i] == '"') {
        for (; command[*i] != '"'; *i += 1)
            if (command[*i] == '\0') {
                my_printf("Error : argument is ending.\n");
                exit(84);
            }
    } else
        for (; command[*i] != ' ' && command[*i] != '\0'; *i += 1);
}

env_t get_env(char *av)
{
    env_t process;
    int arg = 0;
    char *str = malloc(sizeof(char) * (my_strlen(av) + 1));

    my_strcpy(str, av);
    process.cpid = 46;
    process.command = str;
    process.pid = getpid();
    process.path = transfo(av);
    for (arg = 0; process.path[arg] != NULL; arg++);
    arg -= 1;
    process.nb_arg = arg;
    return process;
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}