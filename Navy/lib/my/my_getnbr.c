/*
** EPITECH PROJECT, 2020
** d4
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    int n = 0;
    long j = 0;
    int i = 0;

    for (; str[i] < '0' || str[i] > '9'; i++)
        if (str[i] == '-')
            n++;
    if (str[i] < '0' && str[i] > '9')
        return (0);
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        if (n % 2 == 1)
            j = j - (str[i] - '0');
        if (n % 2 == 0)
            j = j + (str[i] - '0');
        if (j > 2147483647 || j < -2147483648)
            return (0);
        j = j * 10;
    }
    j = j / 10;
    return ((int) j);
}