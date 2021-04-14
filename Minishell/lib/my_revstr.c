/*
** EPITECH PROJECT, 2020
** day_06
** File description:
** Function that reverses a string
*/

int my_strlen(char const *str);

void my_swapchar(char *a, char *b)
{
    char stock_char;

    stock_char = *a;
    *a = *b;
    *b = stock_char;
}

char *my_revstr(char *str)
{
    int first_i;
    int second_i;
    int array_length;

    array_length = my_strlen(str);
    first_i = array_length - 1;
    second_i = 0;
    while (second_i <= first_i){
        my_swapchar(&str[first_i], &str[second_i]);
        first_i--;
        second_i++;
    }
    return (str);
}
