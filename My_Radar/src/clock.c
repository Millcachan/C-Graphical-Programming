/*
** EPITECH PROJECT, 2024
** B-MUL-100-STG-1-1-myradar-camille.billard
** File description:
** clock
*/

#include "../include/my.h"

char *to_str(int nb, char *str)
{
    int i;
    int position = 0;
    int digits[100];

    if (nb == 0)
        return "0";
    for (i = 0; nb != 0; i++) {
        digits[i] = nb % 10;
        nb = nb / 10;
    }
    i--;
    while (i >= 0) {
        str[position] = (char)(digits[i] + '0');
        position ++;
        i--;
    }
    str[position] = '\0';
    return str;
}

void run_clock(clock_type clock, global *radar)
{
    clock.time = sfClock_getElapsedTime(clock.clock);
    clock.seconds = (double)clock.time.microseconds / 1000000.0;
    if (clock.seconds > 0.05 && radar->scene == SIMULATION) {
        radar->text.seconds_int += 1;
        simulation(radar);
        sfClock_restart(clock.clock);
    }
}
