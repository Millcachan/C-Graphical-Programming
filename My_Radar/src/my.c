/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-camille.billard
** File description:
** my
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}

static char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char *src)
{
    return (!src) ? NULL : my_strcpy(malloc((size_t)my_strlen(src) + 1), src);
}

char *my_strcat(char *dest, char *src)
{
    int len = my_strlen(dest) + my_strlen(src);
    int len_dest = my_strlen(dest);

    for (int i = 0; i != len; i++)
        dest[i + len_dest] = src[i];
    dest[len_dest] = '\0';
    return dest;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (1) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        i++;
    }
}

int str_to_int(const char *str)
{
    int result = 0;

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9')
            result = result * 10 + (*str - '0');
        else
            return -84;
        ++str;
    }
    return result;
}
