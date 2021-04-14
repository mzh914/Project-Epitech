/*
** EPITECH PROJECT, 2020
** day_06
** File description:
** Function that copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int i2 = 0;

    while (src[i] != '\0')
    {
        dest[i2] = src[i];
        i++;
        i2 = i2 + 1;
    }
    dest[i2] = '\0';
    return (dest);
}
