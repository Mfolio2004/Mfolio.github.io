/*
** EPITECH PROJECT, 2020
** main test
** File description:
** graphical
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "includes/my.h"
#include "includes/game_param.h"

sfBool close_game(sfRenderWindow* const p_window, sfEvent t_event)
{
    while (sfRenderWindow_pollEvent(p_window, &t_event)) {
        if (t_event.type == sfEvtClosed) {
            sfRenderWindow_close(p_window);
            sfRenderWindow_destroy(p_window);
            return (sfTrue);
        }
    }
    return (sfFalse);
}

void gameloop(sfRenderWindow* const p_window)
{
    sfEvent event;
    t_clock clock = {0};
    t_timeManager timeManager = {0};
    sfVector2f pos = {0, 0};
    sfVector2f size = {1, 1};
    wave_info *wave_inf = (wave_info *) malloc(sizeof(wave_info));

    init_wave(1, 8, wave_inf);
    initialize_clock(&clock);
    initi_time(&timeManager, clock.clock, clock.time, 0);
    while (sfRenderWindow_isOpen(p_window)) {
        if (close_game(p_window, event) == sfTrue)
            return;
        if (pause(p_window) == CLOSE)
            return;
        initi_time(&timeManager, clock.clock, clock.time, 1);
        print_sprite("sprite/map.jpg", pos, size, p_window);
        move_goblin(wave_inf, &timeManager, p_window);
        sfRenderWindow_display(p_window);
    }
}

int main(int ac, char **argv)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "My Defender", sfResize |
sfClose, NULL);
    if (!window)
        return (84);
    sfRenderWindow_setFramerateLimit(window, 30);
    if (start_menu(window) == QUIT)
        return (0);
    gameloop(window);
    return (0);
}
