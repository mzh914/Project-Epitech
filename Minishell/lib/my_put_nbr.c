/*
** EPITECH PROJECT, 2020
** day03
** File description:
** displays number given as a parameter
*/

void my_putchar(char c);

long my_put_nbr(long nb)
{
    long res = 0;
    long nb_dgt = 0;

    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    for (long i = 10; res != nb; i = i * 10) {
        res = nb % i;
        nb_dgt = i;
    }
    for (long i = 1; i < nb_dgt; i++) {
        nb_dgt = nb_dgt / 10;
        res = nb / nb_dgt;
        nb = nb - res * nb_dgt;
        my_putchar(res + '0');
    }
    return (0);
}
