/*
** EPITECH PROJECT, 2021
** PARALLAX MANAGER
** File description:
** parallax_manager
*/

#include "../include/my_runner.h"

void init_parallax(game_t *game)
{
    game->all_parallax = malloc(sizeof(my_parallax_t) * 7);
    for (int i = 0; i < 7; i++) {
        game->all_parallax[i].pos = (sfIntRect) {0, 0, 0, 0};
        if (i == 5)
            game->all_parallax[i].speed = i+2;
        else
            game->all_parallax[i].speed = i + 1;
    }
}

void display_parallax(game_t *game)
{
    for (int i = 0; i < 7; i++) {
        update_background(game, game->all_parallax[i].srpite);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void move_positions(game_t *game)
{
    sfIntRect rect = {0, 0, 0, 0};

    for (int i = 0; i < 7; i++)
    {
        rect = sfSprite_getTextureRect(game->all_parallax[i].srpite);
        move_rect(&rect, game->all_parallax[i].speed, 1920*2);
        sfSprite_setTextureRect(game->all_parallax[i].srpite,
        rect);
    }
}