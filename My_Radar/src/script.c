/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** help
*/

#include "../include/my.h"

int nb_lines(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = 1;
    char buffer[1];
    int count = 0;

    while (size != 0) {
        size = (int)read(fd, buffer, 1);
        if (buffer[0] == '\n')
            count++;
    }
    close(fd);
    return (count + 2);
}

bool valid_file(char **script)
{
    for (int i = 0; script[i]; i++)
        if (script[i][0] != 'T' && script[i][0] != 'A') {
            my_putstr("Invalid script, try a valid one or -h for help", 2);
            return false;
        }
    return true;
}

char **read_script(char *filepath, char **script)
{
    FILE *file = fopen(filepath, "r");
    char *buffer = NULL;
    size_t n;
    int i = 0;

    for (i = 0; getline(&buffer, &n, file) != -1; i++)
        script[i] = my_strdup(buffer);
    script[i] = NULL;
    free(buffer);
    fclose(file);
    return script;
}
