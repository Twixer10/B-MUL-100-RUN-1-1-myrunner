/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-thomas.techer
** File description:
** character_manager2
*/

#include "../include/my_runner.h"

void dead(game_t *game)
{
    game->character.rect = (sfIntRect) {0, 0, 944, 751};
    sfSprite_setTexture(game->character.sprite, game->textures.dead, sfTrue);
    sfSound_setPitch(game->sounds.dead, 0.5);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfSound_play(game->sounds.dead);
}

void move_rect2(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= (max_value - offset))
        return;
    rect->left += offset;
}

void revive(game_t *game)
{
    sfSprite_setTexture(game->character.sprite, game->textures.run, sfTrue);
    game->character.rect = (sfIntRect) {0, 0, 584, 707};
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    sfSound_stop(game->sounds.dead);
}

void display_character_dead(game_t *game)
{
    game->clock.time = sfClock_getElapsedTime(game->clock.clock);
    game->clock.seconds = game->clock.time.microseconds / 1000000.0;
    if (game->clock.seconds > 0.1) {
        move_rect2(&game->character.rect, 944, 9440);
        sfClock_restart(game->clock.clock);
    }
    sfSprite_setPosition(game->character.sprite, game->character.pos);
    sfSprite_setTextureRect(game->character.sprite, game->character.rect);
    sfRenderWindow_drawSprite(game->window, game->character.sprite, NULL);
}