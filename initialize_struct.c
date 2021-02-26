/*
** EPITECH PROJECT, 2021
** initialize_struct
** File description:
** my_defender
*/

#include <SFML/Graphics.h>
#include "includes/my.h"
#include "includes/game_param.h"


Mes couilles sur ton front

text_info init_text(char *text, int size, sfVector2f pos, sfColor color)
{
    text_info text_info = {0};

    text_info.text = my_strcpy(text_info.text, text);
    text_info.color = color;
    text_info.size = size;
    text_info.pos = pos;
    return (text_info);
}

void init_wave(int numWave, int numMobs, wave_info *wave_info)
{
    wave_info->numOfWave = numWave;
    wave_info->numOfMobs = numMobs;
    wave_info->mob_info[numMobs - 1];
    for (int a = 0; a < wave_info->numOfMobs; a++) {
        wave_info->mob_info[a].position.x = 240;
        wave_info->mob_info[a].position.y = 630;
        wave_info->mob_info[a].lastUpdate = 0;
        wave_info->mob_info[a].life = 25;
        wave_info->mob_info[a].damage = 10;
        wave_info->mob_info[a].take.left = 400;
        wave_info->mob_info[a].take.top = 140;
        wave_info->mob_info[a].take.width = 45;
        wave_info->mob_info[a].take.height = 53;
        wave_info->mob_info[a].angle = 1;
    }
}

void initialize_clock(t_clock *t_clock)
{
    t_clock->clock = sfClock_create();
}

void initi_time(t_timeManager * timeManager, sfClock *t_clock,
sfTime t_time, int binairy)
{
    if (binairy == 0) {
        timeManager->i_timeStamp_lastFrame = gettime(t_time, t_clock);
        timeManager->i_timeStamp_currentFrame = 0;
        timeManager->i_deltaTime = 0;
    }
    if (binairy == 1) {
        timeManager->i_timeStamp_currentFrame = gettime(t_time, t_clock);
        timeManager->i_deltaTime = timeManager->i_timeStamp_currentFrame
- timeManager->i_timeStamp_lastFrame;
        timeManager->i_timeStamp_lastFrame = timeManager->
i_timeStamp_currentFrame;
    }
}