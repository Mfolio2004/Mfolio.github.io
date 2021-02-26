/*
** EPITECH PROJECT, 2020
** sum_string_length.c
** File description:
** c
*/

#include <stdarg.h>
#include "../../includes/my.h"

int sum_string_length(int n, ...)
{
    va_list list;
    int result = 0;

    va_start(list, n);
    for (int a = 0; a != n; a++) {
        result = result + my_strlen(va_arg(list, char *));
    }
    va_end(list);
    return (result);
}
