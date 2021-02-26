/*
** EPITECH PROJECT, 2020
** my_strtol
** File description:
** c
*/

int cas_spe(int ret, int value, float deci, int i)
{
    if (i == 1) {
        value = value * -1;
    }
    if (deci != 0) {
        ret = value + deci / 10;
    } else {
        ret = value;
    }
    return (ret);
}

int my_strtol_char(char *str)
{
    int i = 0;
    int value = 0;
    float deci = 0;
    int ret = 0;

    if (str[0] == '-') {
        str = str + 1;
        i = 1;
    }
    for (; *str >= '0' && *str <= '9' || *str == '.'; str = str + 1) {
        if (*str == '.') {
            str = str + 1;
            deci = *str - '0';
        } else {
            value = value + *str - '0';
            value = value * 10;
        }
    }
    value = value / 10;
    ret = cas_spe(ret, value, deci, i);
    return (ret);
}