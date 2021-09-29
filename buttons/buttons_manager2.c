/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-thomas.techer
** File description:
** buttons_manager2
*/

#include "../include/my_runner.h"

void display_pause(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.pause, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.continue_button, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.quit_bouton, NULL);
}

void init_buttons3(game_t *game)
{
    sfSprite_setTexture(game->menu.pause, game->textures.pause, sfTrue);
    sfSprite_setOrigin(game->menu.pause, (sfVector2f) {861/2, 256/2});
    sfSprite_setPosition(game->menu.pause, (sfVector2f) {960, 300});
}
