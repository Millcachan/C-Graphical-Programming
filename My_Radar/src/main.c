/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    int return_value = SUCCESS;
    global radar;

    return_value = usage(argc, argv);
    if (return_value == HELP)
        return SUCCESS;
    if (return_value == ERROR)
        return ERROR;
    init_simulation(&radar, argv[1]);
    run_simulation(&radar);
    free_simulation(&radar);
    return return_value;
}
