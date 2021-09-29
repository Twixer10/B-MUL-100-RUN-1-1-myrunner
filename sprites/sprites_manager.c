/*
** EPITECH PROJECT, 2021
** SPRITES MANAGER
** File description:
** NODSCFND
*/

#include "../include/my_runner.h"

void init_sprite(game_t *game)
{
    game->character.sprite = sfSprite_create();
    sfSprite_setTexture(game->character.sprite, game->textures.idle, sfTrue);
    game->character.pos = (sfVector2f) {50, 660};
    sfSprite_move(game->character.sprite, game->character.pos);
    game->character.rect = (sfIntRect) {0, 0, 584, 707};
    sfSprite_scale(game->character.sprite, (sfVector2f) {0.2, 0.2});
    game->character.is_juping = FALSE;
    game->menu.red = sfSprite_create();
    sfSprite_setTexture(game->menu.red, game->textures.red, sfTrue);
    sfSprite_move(game->menu.red, (sfVector2f) {0, 0});
}