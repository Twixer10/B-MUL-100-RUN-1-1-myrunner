/*
** EPITECH PROJECT, 2021
** CLOSE MANAGER
** File description:
** close_manager
*/

#include "../include/my_runner.h"

void destroy2(game_t *game)
{
    sfTexture_destroy(game->textures.try_bouton);
    sfMusic_destroy(game->sounds.game);
    sfMusic_destroy(game->sounds.menu);
    sfSound_destroy(game->sounds.jump);
    sfSound_destroy(game->sounds.click);
    sfSound_destroy(game->sounds.dead);
    sfTexture_destroy(game->textures.wlquit);
    sfTexture_destroy(game->textures.dead);
    sfTexture_destroy(game->textures.red);
    sfTexture_destroy(game->textures.idle);
    sfTexture_destroy(game->textures.pause);
    sfTexture_destroy(game->textures.continue_btn);
    sfSprite_destroy(game->menu.pause);
    sfSprite_destroy(game->menu.continue_button);
}

void destroy1(game_t *game)
{
    sfSprite_destroy(game->menu.play_bouton);
    sfSprite_destroy(game->menu.quit_bouton);
    sfSprite_destroy(game->menu.try_button);
    sfSprite_destroy(game->menu.win);
    sfSprite_destroy(game->character.sprite);
    for (int i = 0; i < game->map.all_mobs_loaded; i++) {
        sfSprite_destroy(game->mobs[i].sprite);
    }
    sfFont_destroy(game->texts.font);
    sfTexture_destroy(game->textures.win);
    sfTexture_destroy(game->textures.loose);
    sfTexture_destroy(game->textures.mob_fire);
    sfTexture_destroy(game->textures.mob_gost);
    sfTexture_destroy(game->textures.play_bouton);
    sfTexture_destroy(game->textures.quit_bouton);
    sfTexture_destroy(game->textures.run);
    destroy2(game);
}

void stop_music(game_t *game)
{
    sfMusic_stop(game->sounds.game);
    sfMusic_stop(game->sounds.menu);
    sfSound_stop(game->sounds.click);
    sfSound_stop(game->sounds.jump);
    sfSound_stop(game->sounds.dead);
}

void close_game(game_t *game)
{
    destroy1(game);
}