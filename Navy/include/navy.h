/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** navy.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>

#define CTOI(x) (x - '0')
#define hexa_b "0123456789abcdef"

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

char *my_revstr(char *str);

char *my_itoa(int n);

int my_printf(char *str, ...);

void binary_base(int nbr);

int my_convert_base(unsigned int nbr, char *base);

int my_strlen(char const *str);

int my_put_nbr_unsigned(unsigned int nb);

void hexa(int nbr);

void hexa_base_maj(int nbr);

int octal_base(int nbr);

void print_ascii(va_list ap);

void my_putstr_sp(char const *str);

int my_getnbr(char const *str);

int my_put_nbr_long(long nb);

void switch_1_norm(char *str, int i, va_list ap);
int lim_c(char c);
void switch_2_norm(char *str, int i, va_list ap);

void switch_3_norm(char *str, int i, va_list ap);

void switch_4_norm(char *str, int i, va_list ap);

char *open_file(char *filename);

char **generate_map(void);

int lim(char *file, int i);

char **place_boat_1(char *filename);

char **place_boat_2(char *filename);

char **place_boat_3(char *filename);

char **place_boat_4(char *filename);

int error_gestion(char *filename);

void connect_term_3(int pid);

void get_pid(int sig, siginfo_t *info, void *context);

char **term1(int lim, char *filename);

char **term2(int lim, char *filename);

int my_strcmp(char const *s1, char const *s2);

int call_error_gestion(char **av, int ac);

char *get_coor(void);

int error_input(char *input);

int map_my_pos(char *coor);

char **enemi_pos(void);

char *send_data(pid_t pid, int sig);

void caught_data(int sig, siginfo_t *info, void *ucontext);

char *catch_data(int sig);

int error_lenght_boats_1(char *filename);
int error_lenght_boats_2(char *filename);
int error_lenght_boats_3(char *filename);
int error_lenght_boats_4(char *filename);
int error_lenght(char *filename);
void norm_boat_2(char *file, char **map, int lenght, int i);
void norm_boat_3(char *file, char **map, int lenght, int i);
void norm_boat_4(char *file, char **map, int lenght, int i);

int gameloop_p1(int processid2, char **map);

int gameloop_p2(int processid1, char **map);

int is_there_a_boat(char **map, char *coor, int pid, int sig);

void display_eot(char **map, char **ennemy_map);

int boat_down(char **map);
