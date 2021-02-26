/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    while (src[n] != '\0') {
        dest[a] = src[n];
        a = a + 1;
        n++;
    }
    dest[a] = '\0';
    return (dest);
}
