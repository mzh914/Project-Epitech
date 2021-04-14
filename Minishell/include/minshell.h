/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

typedef struct env_s
{
    char *command;
    char **path;
    int nb_arg;
    int pid;
    int cpid;
    int status;
}env_t;

void my_strncpy(char *dest, char const *src, int n);

void increment_i(int *i, char *command);

char **transfo(char *str);

void free_array(char **array);

int count_pointer(char *str);

int my_putstr(char const *str);

int my_printf(const char *format, ...);

void execu_bin(char *str, char **env);

env_t get_env(char *av);

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char const *src);

void error_handler(int ac);

void terminal_loop(char **env);

int my_strcmp(const char *s1, const char *s2);

void set_malloc(void *entity, void *type, int to_allocate);

void phrase_it(char *av);

void change_directory(char **command, char *str, char **env);

void execu(char *str, char **env);

int my_strncmp(char const *s1, char const *s2, int n);

void env_setting(char **command_line);

#endif /* !MY_H_ */
