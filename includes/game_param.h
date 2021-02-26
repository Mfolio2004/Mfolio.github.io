/*
** EPITECH PROJECT, 2020
** headers
** File description:
** my_runner
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define PLAY (0)
#define QUIT (1)
#define NONE (2)
#define CLOSE (3)
#define SPRITEUPDATEPERIOD (200)
#define ENNEMIESSPRITEQTY (7)


typedef struct {
    char *text;
    sfVector2f pos;
    int size;
    sfColor color;
} text_info;

typedef struct {
    int life;
    int damage;
    int lastUpdate;
    int whichSprite;
    int angle;
    sfVector2f position;
    sfIntRect take;
} mob_info;

typedef struct {
    int numOfWave;
    int numOfMobs;
    mob_info mob_info[20];
} wave_info;

typedef struct {
    int i_timeStamp_currentFrame;
    int i_timeStamp_lastFrame;
    int i_deltaTime;
    int i_timeSinceLastScoreUpdate;
} t_timeManager;

typedef struct {
    sfClock *clock;
    sfTime time;
} t_clock;

void print_sprite(char *path, sfVector2f pos, sfVector2f size,
sfRenderWindow *window);

sfVector2i mouse_position(sfEvent event, sfRenderWindow *window);

int gettime(sfTime time, sfClock *clock);

sfBool key_check(sfKeyCode code);

void print_text(sfRenderWindow* window, text_info *text_info);

int start_menu(sfRenderWindow *window);

sfBool close_game(sfRenderWindow* const p_window, sfEvent t_event);

text_info init_text(char *text, int size, sfVector2f pos, sfColor color);

int mouse_on_button(sfRenderWindow *window, sfEvent event,
text_info *play, text_info *quit);

int pause(sfRenderWindow *window);

int menu_pause(sfRenderWindow *window);

int mouse_on_pause(sfRenderWindow *window, sfEvent event,
text_info *button, sfVector2f pos);

void print_goblin(sfIntRect area, wave_info *wave_info, sfRenderWindow *window);

void init_wave(int numWave, int numMobs, wave_info *wave_info);

void initi_time(t_timeManager * timeManager, sfClock *t_clock,
sfTime t_time, int binairy);

void initialize_clock(t_clock *t_clock);

void move_goblin(wave_info *wave_inf, t_timeManager *timeManager,
sfRenderWindow *window);