/*
** EPITECH PROJECT, 2021
** TEXTURES MANAGER
** File description:
** NO DESCRIPTION FOUNDS
*/

#include "../include/my_runner.h"

void init_textures4(game_t *game)
{
    game->textures.continue_btn = sfTexture_createFromFile(
        "./assets/buttons/continueButton.png", NULL);
    game->textures.pause = sfTexture_createFromFile(
        "./assets/buttons/pause.png", NULL);
}

void init_textures3(game_t *game)
{
    game->textures.play_bouton = sfTexture_createFromFile(
        "./assets/buttons/playButton.png", NULL);
    game->textures.quit_bouton = sfTexture_createFromFile(
        "./assets/buttons/quitButton.png", NULL);
    game->textures.try_bouton = sfTexture_createFromFile(
        "./assets/buttons/tryAgainButton.png", NULL);
    game->textures.loose = sfTexture_createFromFile(
        "./assets/buttons/gameOverButton.png", NULL);
    game->textures.win = sfTexture_createFromFile(
        "./assets/buttons/youwin.png", NULL);
    game->textures.idle = sfTexture_createFromFile(
        "./assets/sprites/mainIDLE.png", NULL);
    game->textures.red = sfTexture_createFromFile(
        "./assets/sprites/red_sreen.png", NULL);
    game->textures.dead = sfTexture_createFromFile(
        "./assets/sprites/dead.png", NULL);
    game->textures.wlquit = sfTexture_createFromFile(
        "./assets/buttons/wlQuitButton.png", NULL);
    init_textures4(game);
}

void init_textures2(game_t *game)
{
    for (int i = 0; i < 7; i++) {
        game->all_parallax[i].srpite = sfSprite_create();
        if (i == 6)
            sfSprite_move(game->all_parallax[i].srpite, (sfVector2f) {0, -284});
        sfSprite_setTexture(game->all_parallax[i].srpite,
        game->all_parallax[i].layer, sfTrue);
        sfTexture_setRepeated(game->all_parallax[i].layer, sfTrue);
    }
    game->textures.run = sfTexture_createFromFile(
        "./assets/sprites/main-character.png", NULL);
    game->textures.mob_fire = sfTexture_createFromFile(
        "./assets/sprites/mob1.png", NULL);
    game->textures.mob_gost = sfTexture_createFromFile(
        "./assets/sprites/mob2.png", NULL);
    init_textures3(game);
}

void init_textures(game_t *game)
{
    game->all_parallax[0].layer = sfTexture_createFromFile(
        "./assets/parallax/layer_07_2.png", NULL);
    game->all_parallax[1].layer = sfTexture_createFromFile(
        "./assets/parallax/layer_06.png", NULL);
    game->all_parallax[2].layer = sfTexture_createFromFile(
        "./assets/parallax/layer_05.png", NULL);
    game->all_parallax[3].layer = sfTexture_createFromFile(
        "./assets/parallax/layer_04.png", NULL);
    game->all_parallax[4].layer = sfTexture_createFromFile(
        "./assets/parallax/layer_03.png", NULL);
    game->all_parallax[5].layer = sfTexture_createFromFile(
        "./assets/parallax/layer_02.png", NULL);
    game->all_parallax[6].layer = sfTexture_createFromFile(
        "./assets/parallax/layer_01.png", NULL);
    init_textures2(game);
}