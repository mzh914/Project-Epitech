/*
** EPITECH PROJECT, 2020
** day_06
** File description:
** Reproduce the behavior of the strncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int res = 0;
    while (s1[i] != '\0' || s2[i] != '\0' || i < n) {
        res = res + (s1[i] - s2[i]);
        if (res != 0) {
            return (res);
        }
        i++;
    }
    res = s1[i] - s2[i];
    return (res);
}
