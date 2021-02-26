/*
** EPITECH PROJECT, 2020
** number
** File description:
** c
*/

#include "../../includes/my.h"

int my_put_nbr(int nb);

int number(char *str)
{
    int nbr = 0;

    for (int a = 0; str[a] <= '9' && str[a] >= '0' || str[a] == '-'; a++) {
        if (str[a] == '-' && a == 0) {
            nbr = (str[a + 1] - '0') * -1;
        } else {
            nbr = nbr + str[a] - '0';
        }
        nbr = nbr * 10;
    }
    nbr = nbr / 10;
    return (nbr);
}
