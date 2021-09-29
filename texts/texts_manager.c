/*
** EPITECH PROJECT, 2021
** TEXT MANAGER
** File description:
** NO DESC FOUND
*/

#include "../include/my_runner.h"

void init_text(game_t *game, char *path)
{
    game->texts.font = sfFont_createFromFile("./assets/fonts/LLPIXEL3.ttf");
    game->texts.currentLevel = sfText_create();
    sfText_setString(game->texts.currentLevel, my_strcat("Current Level: ",
    path));
    sfText_setCharacterSize(game->texts.currentLevel, 24);
    sfText_setFont(game->texts.currentLevel, game->texts.font);
    sfText_setPosition(game->texts.currentLevel, (sfVector2f) {5, 5});
    game->texts.score = sfText_create();
    sfText_setString(game->texts.score, "Score: 0");
    sfText_setCharacterSize(game->texts.score, 30);
    sfText_setFont(game->texts.score, game->texts.font);
    sfText_setPosition(game->texts.score, (sfVector2f) {5, 5});
}

void display_current_Level(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->texts.currentLevel, NULL);
}

void display_score(game_t *game)
{
    sfText_setString(game->texts.score, my_strcat("Score: ",
    my_itoa(game->score)));
    sfRenderWindow_drawText(game->window, game->texts.score, NULL);
}