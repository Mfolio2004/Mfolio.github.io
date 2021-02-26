/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** c
*/

#include <stdlib.h>
#include "../../includes/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    dest = malloc(sizeof(char) * my_strlen(src));
    while (src[a] != '\0') {
        dest[a] = src[a];
        a = a + 1;
    }
    dest[a] = '\0';
    return (dest);
}
