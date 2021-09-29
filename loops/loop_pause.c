/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-thomas.techer
** File description:
** loop_pause
*/

#include "../include/my_runner.h"

void unpause_key(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed)
        if (game->event.key.code == sfKeyEscape) {
            game->state = INGAME;
            sfMusic_play(game->sounds.game);
            sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        }
}

void over_continue(game_t *game)
{
    if (game->event.mouseMove.x >= (480 - 861/2) &&
    game->event.mouseMove.x <= (480 + 861/2) &&
    game->event.mouseMove.y >= (900 - 256/2) &&
    game->event.mouseMove.y <= (900 + 256/2)) {
        sfSprite_setScale(game->menu.continue_button, (sfVector2f) {1.3, 1.3});
    } else {
        sfSprite_setScale(game->menu.continue_button, (sfVector2f) {1, 1});
    }
}

void continue_bouton(game_t *game)
{
    if (game->event.mouseButton.x >= (480 - 861/2) &&
    game->event.mouseButton.x <= (480 + 861/2) &&
    game->event.mouseButton.y >= (900 - 256/2) &&
    game->event.mouseButton.y <= (900 + 256/2)) {
        game->state = INGAME;
        sfMusic_play(game->sounds.game);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    }
}

void loop_pause(game_t *game)
{
    sfRenderWindow_display(game->window);
    display_parallax(game);
    display_pause(game);
    display_score(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        unpause_key(game);
        over_quit_bouton(game);
        over_continue(game);
        continue_bouton(game);
        quit_bouton(game);
    }
}