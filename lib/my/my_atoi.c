/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_atoi.c
*/

int my_atoi(char *str)
{
    int nb_digits = 0;
    int result = 0;
    int multi = 1;
    int index = 0;

    for (nb_digits = 0; str[nb_digits] != '\0'; nb_digits++);
    if (str[0] == '-') {
        index += 1;
        nb_digits -= 1;
    }
    for (int i = 0; i != nb_digits - 1; multi *= 10, i++);
    for (; str[index] != '\0'; index++) {
        result += (str[index] - '0') * multi;
        multi /= 10;
    }
    if (str[0] == '-')
        result *= -1;
    return (result);
}
