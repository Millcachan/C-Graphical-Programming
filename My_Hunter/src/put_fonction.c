/*
** EPITECH PROJECT, 2023
** B-CPE
** File description:
** put_fonctions
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int my_putstr(char *str)
{
    return write(1, str, my_strlen(str));
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (1) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
    }
}
