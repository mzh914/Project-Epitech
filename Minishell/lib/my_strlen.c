/*
** EPITECH PROJECT, 2020
** day04
** File description:
** function that counts and returns the number of characters found in the string
** passed as parameter
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
