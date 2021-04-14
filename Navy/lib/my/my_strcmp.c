/*
** EPITECH PROJECT, 2020
** B-CPE-100-PAR-1-4-cpoolday06-luka.boudjelal
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    return 0;
}