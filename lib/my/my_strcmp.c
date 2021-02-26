/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** c
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int cnt1 = my_strlen(s1);
    int cnt2 = my_strlen(s2);
    int cntd = 0;
    int retv = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            retv = s1[i] - s2[i];
            return (retv);
        }
    }
    return (0);
}
