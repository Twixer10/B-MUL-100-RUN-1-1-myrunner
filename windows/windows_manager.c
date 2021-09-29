/*
** EPITECH PROJECT, 2021
** WINDOWS MANAGER
** File description:
** NO DESCRIPTION FOUND
*/

#include "../include/my_runner.h"

void init_windows(game_t *game)
{
    game->state = MENU;
    game->window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
    "My Runner", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->clock.clock = sfClock_create();
}

void update_background(game_t *game, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}