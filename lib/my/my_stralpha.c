/*
** EPITECH PROJECT, 2020
** my_stralpha
** File description:
** c
*/

int my_stralpha(char const *str)
{
    int i = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] <= 'Z' && str[a] >= 'A' ||
            str[a] <= 'z' && str[a] >= 'a') {
            i++;
        }
    }
    return (i);
}
