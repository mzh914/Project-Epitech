/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-4-navy-luka.boudjelal
** File description:
** file.c
*/

#include "navy.h"

char *open_file(char *filename)
{
    char *buf = malloc(sizeof(char) * 33);
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return NULL;
    read(fd, buf, 33);
    close(fd);
    return buf;
}

char **generate_map(void)
{
    int lim = 88;
    int j = 1;
    char **map = malloc(sizeof(char *) * lim - 1);

    for (int k = 0, count = 0, i = 0; k != 8; j++, k++) {
        map[i] = my_itoa(j);
        i++;
        map[i] = "|";
        i++;
        for (; count != 8; i++, count++) {
            if (count != 7)
                map[i] = ". ";
            else
                map[i] = ".";
        }
        count = 0;
        map[i] = "\n";
        i++;
    }
    return map;
}

int error_gestion(char *filename)
{
    char *file = open_file(filename);
    int len = my_strlen(file);

    if (len != 31)
        return 84;
    if (file[0] != '2' || file[8] != '3' || file[16] != '4' ||
    file[24] != '5') {
        my_printf("bad order lenght ships\n");
        return 84;
    }
    for (int i = 0; file[i] != '\0'; i++)
        if ((file[i] >= '1' && file[i] <= '8') || file[i] == '\n' ||
        (file[i] >= 'A' && file[i] <= 'H') || file[i] == ':')
            i++;
        else {
            my_printf("invalid file\n");
            return 84;
        }
    return 0;
}

int call_error_gestion(char **av, int ac)
{
    if (ac != 2 && ac != 3)
        return 84;
    if (ac == 2) {
        if (open_file(av[1]) == NULL || error_gestion(av[1]) == 84)
            return 84;
        if (error_lenght(av[1]) == 84)
            return 84;
    }
    if (ac == 3) {
        if (open_file(av[2]) == NULL || error_gestion(av[2]) == 84)
            return 84;
        if (error_lenght(av[2]) == 84)
            return 84;
    }
    return 0;
}

/*int error_input(char *input)
{
    int j = 0;

    for (int i = 0; j != 1; i++) {
        if ((input[0] < 'A' || input[0] > 'H') || (input[1] < '1' ||
            input[1] > '8')) {
            my_printf("wrong position\nattack: ");
            return 84;
        } else {
            j = 1;
            my_printf("%c%c: ", input[0], input[1]);
        }
    }
    return 1;
}*/