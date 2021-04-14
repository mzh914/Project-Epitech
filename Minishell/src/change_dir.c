/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** change_dir
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <minshell.h>

char *getpath(char *str)
{
    char *path = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (path == NULL)
        exit(84);
    my_strcpy(path, str);
    for (int i = 0; i < 3; i++)
        for (int j = 0; path[j] != '\0'; j++)
            path[j] = path[j + 1];
    return path;
}

char *get_old_path(char **env)
{
    char *old_path = "OLDPWD=";
    int i = 0;
    char *cpy = malloc(sizeof(char) * 8);

    if (cpy == NULL)
        exit(84);
    for (i = 0; env[i] != NULL; i++)
        if (my_strlen(env[i]) > 7) {
            my_strncpy(cpy, env[i], 7);
            if (my_strcmp(old_path, cpy) == 0)
                break;
        }
    cpy = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
    if (cpy == NULL)
        exit(84);
    my_strcpy(cpy, env[i]);
    for (i = 0; i < 7; i++)
        for (int j = 0; cpy[j] != '\0'; j++)
            cpy[j] = cpy[j + 1];
    return cpy;
}

char *get_home_path(char **env)
{
    char *home = "HOME=";
    int i = 0;
    char *cpy = malloc(sizeof(char) * 6);

    if (cpy == NULL)
        exit(84);
    for (i = 0; env[i] != NULL; i++)
        if (my_strlen(env[i]) > 5) {
            my_strncpy(cpy, env[i], 5);
            if (my_strcmp(home, cpy) == 0)
                break;
        }
    cpy = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
    if (cpy == NULL)
        exit(84);
    my_strcpy(cpy, env[i]);
    for (i = 0; i < 5; i++)
        for (int j = 0; cpy[j] != '\0'; j++)
            cpy[j] = cpy[j + 1];
    return cpy;
}

int special_arg(char *path, char **env)
{

    if (my_strcmp(path, "-") == 0) {
        return chdir(get_old_path(env));
    }
    else
        return chdir(path);
}

void change_directory(char **command, char *str, char **env)
{
    int len = 0;
    int c_dir = 0;
    char *path = getpath(str);

    while (command[len] != NULL)
        len++;
    if (len == 2) {
        c_dir = special_arg(path, env);
    } else if (len == 1)
        c_dir = chdir(get_home_path(env));
    else
        my_printf("bash: cd: too many arguments\n");
    if (c_dir == -1)
        my_printf("bash: cd: %s: No such directory.\n", path);
    free(path);
}