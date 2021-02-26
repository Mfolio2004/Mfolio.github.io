/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** c
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int a = 0;
    int b = 0;

    if (nb >= 10) {
        a = nb / 10;
        b = nb % 10;
        my_put_nbr(a);
        my_putchar(b + '0');
    }
    if (nb < 10 && nb >= 0)
        my_putchar(nb + '0');
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        my_put_nbr(nb);
    }
}
