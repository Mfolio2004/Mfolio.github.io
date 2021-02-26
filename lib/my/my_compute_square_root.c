/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** c
*/

int my_compute_square_root(int nb)
{
    int a = nb;
    int b = 1;
    int c = 0;

    while (a > 0) {
        a = a - b;
        b = b + 2;
        c++;
    }
    b -= 2;
    if (a == 0) {
        return (c);
    } else {
        return (0);
    }
}
