/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-thomas.techer
** File description:
** loop_loose
*/

#include "../include/my_runner.h"

void over_try(game_t *game)
{
    if (game->event.mouseMove.x >= (480 - 363) &&
    game->event.mouseMove.x <= (480 + 363) &&
    game->event.mouseMove.y >= (900 - 58.5) &&
    game->event.mouseMove.y <= (900 + 58.5)) {
        sfSprite_setScale(game->menu.try_button, (sfVector2f) {1.3, 1.3});
    } else {
        sfSprite_setScale(game->menu.try_button, (sfVector2f) {1, 1});
    }
}

void try_bouton(game_t *game)
{
    if (game->event.mouseButton.x >= (480 - 363) &&
    game->event.mouseButton.x <= (480 + 363) &&
    game->event.mouseButton.y >= (900 - 58.5) &&
    game->event.mouseButton.y <= (900 + 58.5)) {
        game->score = 0;
        game->character.is_juping = FALSE;
        game->character.pos = (sfVector2f) {50, 660};
        sfSprite_move(game->character.sprite, game->character.pos);
        revive(game);
        if (!game->isInfinite)
            reload_mobs(game);
        else
            reload_infinite_mob(game);
        sfMusic_play(game->sounds.game);
        game->state = INGAME;
    }
}

void loop_loose(game_t *game)
{
    sfRenderWindow_display(game->window);
    update_background(game, game->menu.red);
    sfRenderWindow_drawText(game->window, game->texts.score, NULL);
    display_character_dead(game);
    display_loose(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        over_quit_bouton(game);
        over_try(game);
        quit_bouton(game);
        try_bouton(game);
    }
}