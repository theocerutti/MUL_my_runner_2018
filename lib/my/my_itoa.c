/*
** EPITECH PROJECT, 2018
** my_itoa.c
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    char *new_str = malloc(sizeof(char) * 100);
    int nb_digit = 0;
    int multi = 1;
    int i = 0;

    if (nb == 0) {
        nb_digit = 1;
        multi *= 10;
    }
    for (long nb_s = nb; nb_s > 0; nb_s /= 10, multi *= 10)
        nb_digit += 1;
    multi /= 10;
    for (i = 0; i != nb_digit; i++, multi /= 10)
        new_str[i] = nb / multi % 10 + '0';
    new_str[i] = '\0';
    return (new_str);
}
