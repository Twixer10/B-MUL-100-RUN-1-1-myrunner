/*
** EPITECH PROJECT, 2021
** BUTTONS MANAGER
** File description:
** buttons_manager
*/

#include "../include/my_runner.h"

void init_buttons2(game_t *game)
{
    game->menu.try_button = sfSprite_create();
    game->menu.loose = sfSprite_create();
    game->menu.win = sfSprite_create();
    game->menu.continue_button = sfSprite_create();
    game->menu.pause = sfSprite_create();
    sfSprite_setTexture(game->menu.try_button, game->textures.try_bouton,
    sfTrue);
    sfSprite_setOrigin(game->menu.try_button, (sfVector2f) {363, 58.5});
    sfSprite_setPosition(game->menu.try_button, (sfVector2f) {480, 900});
    sfSprite_setTexture(game->menu.loose, game->textures.loose, sfTrue);
    sfSprite_setOrigin(game->menu.loose, (sfVector2f) {623, 99.5});
    sfSprite_setPosition(game->menu.loose, (sfVector2f) {960, 300});
    sfSprite_setTexture(game->menu.win, game->textures.win, sfTrue);
    sfSprite_setOrigin(game->menu.win, (sfVector2f) {617.5, 128});
    sfSprite_setPosition(game->menu.win, (sfVector2f) {960, 300});
    sfSprite_setTexture(game->menu.continue_button, game->textures.continue_btn,
    sfTrue);
    sfSprite_setOrigin(game->menu.continue_button, (sfVector2f) {348.5, 59});
    sfSprite_setPosition(game->menu.continue_button, (sfVector2f) {480, 900});
    init_buttons3(game);
}

void init_buttons(game_t *game)
{
    game->menu.play_bouton = sfSprite_create();
    sfSprite_setTexture(game->menu.play_bouton, game->textures.play_bouton,
    sfTrue);
    sfSprite_setOrigin(game->menu.play_bouton, (sfVector2f) {181, 58.5});
    sfSprite_setPosition(game->menu.play_bouton, (sfVector2f) {480, 900});

    game->menu.quit_bouton = sfSprite_create();
    sfSprite_setTexture(game->menu.quit_bouton, game->textures.quit_bouton,
    sfTrue);
    sfSprite_setOrigin(game->menu.quit_bouton, (sfVector2f) {168.5, 53.5});
    sfSprite_setPosition(game->menu.quit_bouton, (sfVector2f) {1440, 900});
    init_buttons2(game);
}

void display_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.play_bouton, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.quit_bouton, NULL);
}

void display_loose(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.loose, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.try_button, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.quit_bouton, NULL);
}

void display_win(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.win, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.try_button, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.quit_bouton, NULL);
}