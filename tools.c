/*
** EPITECH PROJECT, 2021
** principal fonctions
** File description:
** my_defender
*/

#include "includes/my.h"
#include "includes/game_param.h"
#include <SFML/Graphics.h>

void print_sprite(char *path, sfVector2f pos, sfVector2f size,
sfRenderWindow *window)
{
    sfTexture* font;
    sfSprite* sp_font;

    font = sfTexture_createFromFile(path, NULL);
    sp_font = sfSprite_create();
    sfSprite_setTexture(sp_font, font, sfTrue);
    sfSprite_move(sp_font, pos);
    sfSprite_setScale(sp_font, size);
    sfRenderWindow_drawSprite(window, sp_font, NULL);
    sfTexture_destroy(font);
    sfSprite_destroy(sp_font);
}

void print_text(sfRenderWindow* window, text_info *text_info)
{
    sfText* score;
    sfFont* font;

    score = sfText_create();
    font = sfFont_createFromFile("write.ttf");
    sfText_setString(score, text_info->text);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, text_info->size);
    sfText_setColor(score, sfWhite);
    sfText_move(score, text_info->pos);
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
}

int gettime(sfTime time, sfClock *clock)
{
    int mseconds;

    time = sfClock_getElapsedTime(clock);
    mseconds = time.microseconds / 1000;
    return (mseconds);
}

sfVector2i mouse_position(sfEvent event, sfRenderWindow *window)
{
    sfVector2i mouse_pos = {0, 0};

    mouse_pos = sfMouse_getPositionRenderWindow(window);
    return (mouse_pos);
}

sfBool key_check(sfKeyCode code)
{
    if (sfKeyboard_isKeyPressed(code) == sfTrue)
        return (sfTrue);
    return (sfFalse);
}