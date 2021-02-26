/*
** EPITECH PROJECT, 2021
** menu
** File description:
** my_defender
*/

#include <SFML/Graphics.h>
#include "../includes/my.h"
#include "../includes/game_param.h"

text_info print_button(sfRenderWindow *window, int offset,
char *word, sfVector2f pos_play)
{
    sfVector2f size = {1.5, 1.2};
    text_info play = {0};

    print_sprite("sprite/boutton.png", pos_play, size, window);
    pos_play.x += offset;
    pos_play.y += 20;
    play = init_text(word, 37, pos_play, sfWhite);
    print_text(window, &play);
    return (play);
}

int which_button(sfRenderWindow *window, sfEvent event)
{
    sfVector2f size = {1.5, 1.2};
    sfVector2f pos = {280, 220};
    text_info play = {0};
    text_info quit = {0};

    play = print_button(window, 55, "PLAY", pos);
    pos.y += 130;
    quit = print_button(window, 55, "QUIT", pos);
    if (mouse_on_button(window, event, &play, &quit)
== PLAY)
        return (PLAY);
    else if (mouse_on_button(window, event, &play, &quit)
== QUIT)
        return (QUIT);
    return (NONE);
}

int start_menu(sfRenderWindow *window)
{
    sfEvent event;
    sfVector2f offset = {300, 40};
    sfVector2f pos = {0, 0};
    sfVector2f size = {1, 1};

    print_sprite("sprite/fond acceuil.jpg", pos, size, window);
    while (sfRenderWindow_isOpen(window)) {
        if (close_game(window, event) == sfTrue)
            return (1);
        print_sprite("sprite/logo.png", offset, size, window);
        if (which_button(window, event) != NONE)
            return (which_button(window, event));
        sfRenderWindow_display(window);
    }
    sfRenderWindow_clear(window, sfBlack);
    return (0);
}

int button_pause(sfRenderWindow *window, char *text[3])
{
    sfEvent event;
    sfVector2f pos = {280, 120};
    sfVector2f size = {1.5, 1.2};
    text_info resume = {0};
    int offset = 35;

    for (int a = 0; a < 3; a++, pos.y += 110) {
        if (a == 1)
            offset = 20;
        else if (a == 2)
            offset = 60;
        resume = print_button(window, offset, text[a], pos);
        if (mouse_on_pause(window, event, &resume, pos) != NONE)
            return (mouse_on_pause(window, event, &resume, pos));
    }
}

int menu_pause(sfRenderWindow *window)
{
    sfEvent event;
    char *word[3] = {"RESUME", "RESTART", "QUIT"};

    while (sfRenderWindow_isOpen(window)) {
        if (close_game(window, event) == sfTrue)
            return (CLOSE);
        if (button_pause(window, word) == PLAY)
            break;
        else if (button_pause(window, word) == CLOSE) {
            sfRenderWindow_clear(window, sfBlack);
            return (CLOSE);
        }
        sfRenderWindow_display(window);
    }
    sfRenderWindow_clear(window, sfBlack);
}