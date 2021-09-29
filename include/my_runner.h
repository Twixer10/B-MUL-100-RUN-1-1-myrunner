/*
** EPITECH PROJECT, 2021
** MY RUNNER
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include "./my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum game_state_h {
    MENU = 0,
    INGAME = 1,
    PAUSE = 2,
    WIN = 3,
    LOOSE = 4,
    CLOSE = 5,
} game_state_t;

typedef struct my_parallax_h
{
    sfTexture *layer;
    sfIntRect pos;
    sfSprite *srpite;
    int speed;
} my_parallax_t;

typedef struct clock_manager_h
{
    sfClock *clock;
    sfTime time;
    float seconds;
} my_clock_t;

typedef struct menu_manager_h
{
    sfSprite *play_bouton;
    sfSprite *quit_bouton;
    sfSprite *win;
    sfSprite *loose;
    sfSprite *try_button;
    sfSprite *red;
    sfSprite *continue_button;
    sfSprite *pause;
} menu_t;

typedef struct text_manager_h
{
    sfFont *font;
    sfText *currentLevel;
    sfText *score;
} text_t;

typedef struct textures_manager_h
{
    sfTexture *run;
    sfTexture *mob_fire;
    sfTexture *mob_gost;
    sfTexture *play_bouton;
    sfTexture *quit_bouton;
    sfTexture *try_bouton;
    sfTexture *loose;
    sfTexture *win;
    sfTexture *idle;
    sfTexture *dead;
    sfTexture *red;
    sfTexture *wlquit;
    sfTexture *continue_btn;
    sfTexture *pause;
} all_textures_t;

typedef struct character_manager_h
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    my_bool is_juping;
} character_t;

typedef struct mob_manager_h
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f default_pos;
    int type;
} mob_t;

typedef struct map_manager_h
{
    char *map;
    int all_mobs;
    int all_mobs_loaded;
} map_manager_t;

typedef struct sound_manager_h
{
    sfMusic *menu;
    sfMusic *game;
    sfSound *click;
    sfSound *jump;
    sfSound *dead;
} sound_manager_t;

typedef struct game_manager_h
{
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *theme;
    game_state_t state;
    menu_t menu;
    my_clock_t clock;
    my_clock_t clock_jump;
    my_clock_t clock_mobs;
    my_parallax_t *all_parallax;
    all_textures_t textures;
    character_t character;
    map_manager_t map;
    mob_t *mobs;
    text_t texts;
    my_bool isInfinite;
    int score;
    sound_manager_t sounds;
} game_t;


void switch_music(game_t *game, sfMusic *sound);
void init_windows(game_t *game);
void move_positions(game_t *game);
void display_parallax(game_t *game);
void update_background(game_t *game, sfSprite *sprite);
void init_parallax(game_t *game);
void init_textures(game_t *game);
void loop_menu(game_t *game);
void loop_in_game(game_t *game);
void loop_loose(game_t *game);
void loop_win(game_t *game);
void loop_close(game_t *game);
void loop_pause(game_t *game);
void init_sprite(game_t *game);
void display_character(game_t *game);
void move_rect(sfIntRect *rect, int offset, int max_value);
void jump(game_t *game);
int check_map(char *path, game_t *game);
void create_mob(game_t *game, int type, int x, int y);
void display_mobs(game_t *game);
int cheack_mobs(game_t *game);
void init_text(game_t *game, char *path);
void display_current_Level(game_t *game);
void display_menu(game_t *game);
void init_buttons(game_t *game);
void check_victory(game_t *game);
void display_score(game_t *game);
void display_loose(game_t *game);
void display_win(game_t *game);
void over_quit_bouton(game_t *game);
void quit_bouton(game_t *game);
int reload_mobs(game_t *game);
void close_game(game_t *game);
void init_songs(game_t *game);
void randomise_location(mob_t *mob);
void create_random_mob(game_t *game);
void reload_infinite_mob(game_t *game);
void display_character_dead(game_t *game);
void dead(game_t *game);
void revive(game_t *game);
void over_try(game_t *game);
void try_bouton(game_t *game);
void stop_music(game_t *game);
void display_pause(game_t *game);
void init_buttons3(game_t *game);

#define HELP_MESSAGE "\nUSAGE\n\t./my_runner <parameters>\n\nDESCRIPTION\
\n\t./my_runner -h \t Display this message\n\t./my_runner -i \t Start the \
game in Infinite Mode\n\t./my_runner <path_to_map_file> \t Start the \
game whith a specified map\n\n\nUSER INTERACTIONS\n\nESCAPE KEY \t Pause \
/ Unpause the game\nSPACE KEY \t Jump in the game\nMOUSE CLICK \
\t Interact with buttons\n\n\
Default maps are located in 'assets/maps/'"

#endif /* !MY_RUNNER_H_ */
