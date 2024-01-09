/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** help
*/

#include "../include/my.h"

void print_help(void)
{
    my_putstr("Air traffic simulation panel\n", 1);
    my_putchar('\n', 1);
    my_putstr("USAGE\n", 1);
    my_putstr(" ./my_radar [OPTIONS] path_to_script\n", 1);
    my_putstr("  path_to_script    The path to the script file.\n", 1);
    my_putchar('\n', 1);
    my_putstr("OPTIONS\n", 1);
    my_putstr(" -h                print the usage and quit.\n", 1);
    my_putchar('\n', 1);
    my_putstr("USER INTERACTIONS\n", 1);
    my_putstr(" 'L' key        enable/disable hitboxes and areas.\n", 1);
    my_putstr(" 'S' key        enable/disable sprites.\n", 1);
}

bool help(char *arg)
{
    if (my_strcmp(arg, "-h") != 0)
        return false;
    print_help();
    return true;
}

bool wrong_args(int argc, char **argv)
{
    if (argc == 2)
        return false;
    my_putstr(argv[0], 2);
    my_putstr(": bad arguments: ", 2);
    my_putnbr(argc - 1, 2);
    my_putstr(" given but 1 is required\n", 2);
    my_putstr("retry with -h\n", 2);
    return true;
}

int nodir(char *filepath)
{
    int dir = open(filepath, O_RDONLY);

    if (dir != -1) {
        close(dir);
        return false;
    }
    return true;
}

int usage(int argc, char **argv)
{
    if (wrong_args(argc, argv))
        return ERROR;
    if (help(argv[1]))
        return HELP;
    if (nodir(argv[1])) {
        my_putstr("Wrong file: ", 2);
        my_putstr(argv[1], 2);
        my_putstr(" does not exist\n", 2);
        return ERROR;
    }
    return SUCCESS;
}
