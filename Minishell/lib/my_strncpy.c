/*
** EPITECH PROJECT, 2020
** day_06
** File description:
** function that copies n characters from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int i2 = 0;

    while (i < n)
    {
        dest[i2] = src[i];
        i++;
        i2 = i2 + 1;
    }
    dest[i2] = '\0';
    return (dest);
}
