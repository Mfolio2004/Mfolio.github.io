/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** c
*/

#include "../../includes/my.h"

char *my_revstr(char *str)
{
    char a;
    int b = my_strlen(str) - 1;
    int len = b/2;
    for (int c = 0; c <= len; c++) {
        a = str[c];
        str[c] = str[b];
        str[b] = a;
        b--;
    }
    return (str);
}
