/*
** EPITECH PROJECT, 2021
** LOOP IN GAME
** File description:
** NO DESCRIPTION FOUND
*/

#include "../include/my_runner.h"

void pause(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyEscape) {
            game->state = PAUSE;
            sfMusic_pause(game->sounds.game);
            sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        }
    }
}

void loop_in_game(game_t *game)
{
    sfRenderWindow_display(game->window);
    display_parallax(game);
    move_positions(game);
    display_character(game);
    display_mobs(game);
    display_score(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        jump(game);
        pause(game);
    }
}

