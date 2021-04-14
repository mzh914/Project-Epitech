/*
** EPITECH PROJECT, 2020
** day07
** File description:
** function that concatenate 2 strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (int j = 0; src[i] != '\0'; j++)
    {
        if (dest[j] == '\0')
        {
            while (src[i] != '\0') {
                dest[j] = src[i];
                i++;
                j++;
            }
            dest[j] = '\0';
            return (dest);
        }
    }
    return dest;
}