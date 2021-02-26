/*
** EPITECH PROJECT, 2021
** button
** File description:
** my_defender
*/

#include <SFML/Graphics.h>
#include "../includes/my.h"
#include "../includes/game_param.h"

int mouse_on_button(sfRenderWindow *window, sfEvent event,
text_info *play, text_info *quit)
{
    sfVector2i mouse = {0, 0};

    mouse = mouse_position(event, window);
    if (mouse.x < 500 && mouse.x > 300 && mouse.y > 220 && mouse.y < 345) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            return (PLAY);
        print_text(window, play);
    }
    if (mouse.x < 500 && mouse.x > 300 && mouse.y > 350 && mouse.y < 475) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            return (QUIT);
        print_text(window, quit);
    }
    return (NONE);
}

int mouse_on_pause(sfRenderWindow *window, sfEvent event,
text_info *button, sfVector2f pos)
{
    sfVector2i mouse = {0, 0};

    mouse = mouse_position(event, window);
    if (mouse.x < pos.x + 220 && mouse.x > pos.x
&& mouse.y > pos.y && mouse.y < pos.y + 80) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            if (my_strcmp(button->text, "RESUME") == 0)
                return (PLAY);
            else if (my_strcmp(button->text, "QUIT") == 0)
                return (CLOSE);
        }
        print_text(window, button);
    }
    return (NONE);
}

int pause(sfRenderWindow *window)
{
    sfVector2i mouse = {0, 0};

    mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > 735 && mouse.x < 780 && mouse.y > 15 && mouse.y < 75 &&
sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        if (menu_pause(window) == CLOSE)
            return (CLOSE);
}