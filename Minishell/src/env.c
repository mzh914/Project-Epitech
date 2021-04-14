/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** env
*/

#include <stdlib.h>
#include <minshell.h>

void env_setting(char **command_line)
{
    int to_return = 0;
    int count = 0;

    for (int i = 0; command_line[i] != NULL; i++)
        count++;
    if (my_strcmp(command_line[0], "setenv") == 0) {
        if (count != 3)
            my_printf("Error : number of arguments incorrect, 3 is required\n");
        else
            to_return = setenv(command_line[1], command_line[2], 1);
    } else if (my_strcmp(command_line[0], "unsetenv") == 0) {
        if (count != 2)
            my_printf("Error : number of arguments incorrect, 2 is required\n");
        else
            to_return = unsetenv(command_line[1]);
    }
    if (to_return == -1)
        my_printf("Error : an error has occured\n");
}