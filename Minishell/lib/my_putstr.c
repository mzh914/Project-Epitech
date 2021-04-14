/*
** EPITECH PROJECT, 2020
** D04
** File description:
** function that displays, one-by-one, the characters of a string.
*/

void my_putchar(char c);

int my_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
    return 1;
}
