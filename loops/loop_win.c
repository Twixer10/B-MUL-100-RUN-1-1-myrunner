/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-thomas.techer
** File description:
** loop_win
*/

#include "../include/my_runner.h"

void loop_win(game_t *game)
{
    sfRenderWindow_display(game->window);
    display_parallax(game);
    display_score(game);
    display_win(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        over_quit_bouton(game);
        over_try(game);
        quit_bouton(game);
        try_bouton(game);
    }
}