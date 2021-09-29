/*
** EPITECH PROJECT, 2021
** SOUND MANAGER
** File description:
** NO DESCRIPTION FOUND
*/

#include "../include/my_runner.h"

void switch_music(game_t *game, sfMusic *sound)
{
    sfMusic_stop(game->sounds.game);
    sfMusic_stop(game->sounds.menu);
    sfMusic_play(sound);
    sfMusic_setPitch(sound, 2);
    sfMusic_setLoop(sound, sfTrue);
}

void init_songs(game_t *game)
{
    game->sounds.menu = sfMusic_createFromFile("./assets/sounds/menu.ogg");
    sfMusic_setPitch(game->sounds.menu, 1.5);
    game->sounds.game = sfMusic_createFromFile("./assets/sounds/game.ogg");
    game->sounds.jump = sfSound_create();
    sfSound_setBuffer(game->sounds.jump, sfSoundBuffer_createFromFile(
        "./assets/sounds/jump.wav"));
    game->sounds.click = sfSound_create();
    sfSound_setBuffer(game->sounds.click, sfSoundBuffer_createFromFile(
        "./assets/sounds/click.wav"));
    game->sounds.dead = sfSound_create();
    sfSound_setBuffer(game->sounds.dead, sfSoundBuffer_createFromFile(
        "./assets/sounds/dead.wav"));
    sfSound_setVolume(game->sounds.jump, 25);
}
