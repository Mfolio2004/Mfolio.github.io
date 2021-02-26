/*
** EPITECH PROJECT, 2021
** ennemies
** File description:
** my_defender
*/

#include <SFML/Graphics.h>
#include "includes/my.h"
#include "includes/game_param.h"

void way_goblin(wave_info *wave_info)
{
    mob_info *mob_info = &wave_info->mob_info[0];

    if (mob_info->position.y == 505 && mob_info->position.x < 400) {
        mob_info->take.top = 67;
        mob_info->position.x += 1;
    } else if (mob_info->position.x == 400) {
        mob_info->take.top = 140;
        mob_info->position.y -= 1;
    } else {
        mob_info->position.y -= 1;
    }
}

void print_goblin(sfIntRect area, wave_info *wave_info, sfRenderWindow *window)
{
    sfTexture* font;
    sfSprite* sp_font;
    sfVector2f size = {1 , 1};

    way_goblin(wave_info);
    font = sfTexture_createFromFile("sprite/goblin.png", &area);
    sp_font = sfSprite_create();
    sfSprite_setTexture(sp_font, font, sfTrue);
    sfSprite_move(sp_font, wave_info->mob_info[0].position);
    sfSprite_setScale(sp_font, size);
    sfRenderWindow_drawSprite(window, sp_font, NULL);
    sfTexture_destroy(font);
    sfSprite_destroy(sp_font);
}

void move_goblin(wave_info *wave_inf, t_timeManager *timeManager,
sfRenderWindow *window)
{
    wave_inf->mob_info[0].lastUpdate += timeManager->i_deltaTime;
    if (wave_inf->mob_info[0].lastUpdate > SPRITEUPDATEPERIOD) {
        wave_inf->mob_info[0].whichSprite = ((wave_inf->mob_info[0].
whichSprite) + 1) % ENNEMIESSPRITEQTY;
        wave_inf->mob_info[0].lastUpdate = 0;
        wave_inf->mob_info[0].take.left -= 65;
        if (wave_inf->mob_info[0].take.left < 65)
            wave_inf->mob_info[0].take.left = 400;
    }
    print_goblin(wave_inf->mob_info[0].take, wave_inf, window);
}