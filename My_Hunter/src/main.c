/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../include/my.h"

int help(void)
{
    char buf[527];
    int fd = open("asset/help.txt", O_RDONLY);

    read(fd, buf, 527);
    for (int i = 0; buf[i + 1] != '\0'; i++)
        write(1, &buf[i], 1);
    close(fd);
    write(1, "\n", 1);
    return 0;
}

int error_handling(int argc, char **argv)
{
    if (argc != 1 && argc != 2) {
        write(2, "Invalid number of arguments :\n", 30);
        write(2, "./my_hunter to play and ./my_hunter -h for help\n", 48);
        return 84;
    }
    if (argc == 2 && my_strcmp(argv[1], "-h") != 0) {
        write(2, "Invalid arguments :\n", 20);
        write(2, "./my_hunter to play and ./my_hunter -h for help\n", 48);
        return 84;
    }
}

int main(int argc, char **argv)
{
    global_t global;

    if (error_handling(argc, argv) == 84)
        return 84;
    if (argc == 2)
        return help();
    init(&global);
    my_putstr("\n>Game : succefully initialized\n");
    menu(&global);
    return 0;
}
