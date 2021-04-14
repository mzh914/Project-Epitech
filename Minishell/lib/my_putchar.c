/*
** EPITECH PROJECT, 2020
** my_puthcar
** File description:
** display character
*/

int write(int fd, char *Buff, int NumBytes);

void my_putchar(char c)
{
    write(1, &c, 1);
}