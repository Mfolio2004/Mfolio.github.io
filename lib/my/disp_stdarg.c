/*
** EPITECH PROJECT, 2020
** disp_stdarg.c
** File description:
** c
*/

#include <stdarg.h>
#include "../../includes/my.h"

void disp_stdarg(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int a = 1; s[a] != '\0'; a++) {
        if (s[a] == 's') {
            my_putstr(va_arg(list, char *));
        } else if (s[a] == 'i') {
            my_put_nbr(va_arg(list, int));
        }
        if (s[a] == 'c') {
            my_putchar(va_arg(list, int));
        } else if (s[a] == '\n') {
            my_putchar('\n');
        }
    }
}
