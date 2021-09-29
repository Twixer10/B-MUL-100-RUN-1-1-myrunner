/*
** EPITECH PROJECT, 2021
** LOOP MENU
** File description:
** NODSCFND
*/

#include "../include/my_runner.h"

void over_play_bouton(game_t *game)
{
    if (game->event.mouseMove.x >= (480 - 181) &&
    game->event.mouseMove.x <= (480 + 181) &&
    game->event.mouseMove.y >= (900 - 58.5) &&
    game->event.mouseMove.y <= (900 + 58.5)) {
        sfSprite_setScale(game->menu.play_bouton, (sfVector2f) {1.3, 1.3});
    } else {
        sfSprite_setScale(game->menu.play_bouton, (sfVector2f) {1, 1});
    }
}

void over_quit_bouton(game_t *game)
{
    if (game->event.mouseMove.x >= (1440 - 180.5) &&
    game->event.mouseMove.x <= (1440 + 180.5) &&
    game->event.mouseMove.y >= (900 - 65.5) &&
    game->event.mouseMove.y <= (900 + 65.5)) {
        sfSprite_setScale(game->menu.quit_bouton, (sfVector2f) {1.3, 1.3});
    } else {
        sfSprite_setScale(game->menu.quit_bouton, (sfVector2f) {1, 1});
    }
}

void play_bouton(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.x >= (480 - 181) &&
        game->event.mouseButton.x <= (480 + 181) &&
        game->event.mouseButton.y >= (900 - 58.5) &&
        game->event.mouseButton.y <= (900 + 58.5)) {
            switch_music(game, game->sounds.game);
            sfSprite_setTexture(game->character.sprite, game->textures.run,
            sfTrue);
            sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
            sfSprite_setTexture(game->menu.quit_bouton, game->textures.wlquit,
            sfTrue);
            game->state = INGAME;
        }
}

void quit_bouton(game_t *game)
{
    if (game->event.mouseButton.x >= (1440 - 180.5) &&
    game->event.mouseButton.x <= (1440 + 180.5) &&
    game->event.mouseButton.y >= (900 - 65.5) &&
    game->event.mouseButton.y <= (900 + 65.5)) {
        game->state = CLOSE;
        stop_music(game);
        sfRenderWindow_close(game->window);
    }
}

void loop_menu(game_t *game)
{
    sfRenderWindow_display(game->window);
    display_parallax(game);
    display_current_Level(game);
    display_menu(game);
    display_character(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        over_play_bouton(game);
        over_quit_bouton(game);
        play_bouton(game);
        quit_bouton(game);
    }
}
