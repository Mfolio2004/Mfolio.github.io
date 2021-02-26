/*
** EPITECH PROJECT, 2020
** sum_numbers
** File description:
** c
*/

#include <stdarg.h>
#include "../../includes/my.h"

int sum_numbers(int n, ...)
{
    va_list list;
    int result = 0;

    va_start(list, n);
    for (int a = 0; a != n; a++) {
        result = result + va_arg(list, int);
    }
    va_end(list);
    return (result);
}
