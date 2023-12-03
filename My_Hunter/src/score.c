/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-camille.billard
** File description:
** score
*/

#include "../include/my.h"

static long long int my_getnbr(char *str)
{
    long long nbr = 0;
    int i = 0;
    int signe = 1;

    while (str[i] == '-' || str[i] == '+' && str[i] != '\0') {
        if (str[i] == '-')
            signe = signe * (-1);
            i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr * 10 + (str[i] - 48);
        i++;
    }
    return (nbr * signe);
}

void destroy_text(global_t *global)
{
    my_putstr("\n>Game text : successfully destroyed\n");
    sfText_destroy(global->game.score.int_text);
    sfText_destroy(global->game.score.score_text);
    sfText_destroy(global->game.score.best_int_text);
    sfText_destroy(global->game.score.best_score_text);
}

void new_best_score(game_t *game)
{
    int fd = open("asset/best_score.txt", O_RDWR);

    write(fd, to_str(game->score.best, game->score.str),
    my_strlen(to_str(game->score.best, game->score.str)));
}

int read_best_score(void)
{
    char buf[100];
    int fd = open("asset/best_score.txt", O_RDWR);

    read(fd, buf, 100);
    return (my_getnbr(buf));
}

static void set_best_score(score_t *score)
{
    sfText_setString(score->best_score_text, "The Best Score is");
    sfText_setColor(score->best_score_text, sfBlack);
    sfText_setFont(score->best_score_text, score->font);
    sfText_setCharacterSize(score->best_score_text, score->size);
    sfText_setPosition(score->best_score_text, score->best_score_pos);
    sfText_setString(score->best_int_text, to_str(score->best, score->str));
    sfText_setColor(score->best_int_text, sfBlack);
    sfText_setFont(score->best_int_text, score->font);
    sfText_setCharacterSize(score->best_int_text, score->size);
    sfText_setPosition(score->best_int_text, score->best_int_pos);
}

void set_score(score_t *score)
{
    my_putstr("\n>Game text : successfully set\n");
    sfText_setString(score->score_text, "Your Score is");
    sfText_setColor(score->score_text, sfBlack);
    sfText_setFont(score->score_text, score->font);
    sfText_setCharacterSize(score->score_text, score->size);
    sfText_setPosition(score->score_text, score->score_pos);
    sfText_setString(score->int_text, to_str(score->score_int, score->str));
    sfText_setColor(score->int_text, sfBlack);
    sfText_setFont(score->int_text, score->font);
    sfText_setCharacterSize(score->int_text, score->size);
    sfText_setPosition(score->int_text, score->int_pos);
    set_best_score(score);
}

char *to_str(long long nb, char *str)
{
    int i;
    int ndigits = 0;
    int position = 0;
    int digits[100];

    if (nb == 0)
        return "0";
    for (i = 0; nb != 0; i++) {
        digits[i] = nb % 10;
        nb = nb / 10;
    }
    ndigits = i;
    i--;
    while (i >= 0) {
        str[position] = (digits[i] + '0');
        position ++;
        i--;
    }
    str[position] = '\0';
    return str;
}
