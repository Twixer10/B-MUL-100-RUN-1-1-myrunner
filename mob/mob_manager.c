/*
** EPITECH PROJECT, 2021
** MOB MANAGER
** File description:
** NO DESCRIPTION FOUND
*/

#include "../include/my_runner.h"

void check_victory(game_t *game)
{
    if (!game->isInfinite) {
        for (int i = 0; i < game->map.all_mobs_loaded; i++) {
            if (game->mobs[i].pos.x > -100) {
                return;
            }
        }
        game->state = WIN;
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    } else {
        for (int i = 0; i < game->map.all_mobs_loaded; i++) {
            if (game->mobs[i].pos.x < -100) {
                randomise_location(&game->mobs[i]);
            }
        }
    }
}

void new_loc(game_t *game, mob_t *mob)
{
    if (!game->isInfinite) {
        mob->pos = sfSprite_getPosition(mob->sprite);
        mob->pos.x -= 11;
        sfSprite_setPosition(mob->sprite, mob->pos);
    } else {
        mob->pos = sfSprite_getPosition(mob->sprite);
        mob->pos.x -= 11 + (game->score / 500.0);
        sfSprite_setPosition(mob->sprite, mob->pos);
    }
}

void display_mobs(game_t *game)
{
    game->clock_mobs.time = sfClock_getElapsedTime(game->clock_mobs.clock);
    game->clock_mobs.seconds = game->clock_mobs.time.microseconds / 1000000.0;
    for (int i = 0; i < game->map.all_mobs_loaded; i++) {
        new_loc(game, &game->mobs[i]);
        if (game->clock_mobs.seconds > 0.05) {
            move_rect(&game->mobs[i].rect, (game->mobs[i].type == 1?512:40),
            (game->mobs[i].type == 1?6144:240));
            sfClock_restart(game->clock_mobs.clock);
        }
        sfSprite_setTextureRect(game->mobs[i].sprite, game->mobs[i].rect);
        sfRenderWindow_drawSprite(game->window, game->mobs[i].sprite, NULL);
    }
    check_victory(game);
    if (game->isInfinite)
        sfMusic_setPitch(game->sounds.game, 0.5 + game->score/5000.0);
    else
        sfMusic_setPitch(game->sounds.game, 1);
}

void inject_mob(game_t *game, mob_t mob)
{
    game->mobs[game->map.all_mobs_loaded] = mob;
    game->map.all_mobs_loaded = game->map.all_mobs_loaded + 1;
}

void create_mob(game_t *game, int type, int x, int y)
{
    mob_t mob;

    mob.pos = (sfVector2f) {x, y};
    mob.default_pos = (sfVector2f) {x, y};
    mob.sprite = sfSprite_create();
    if (type == 1) {
    sfSprite_setTexture(mob.sprite, game->textures.mob_fire, sfTrue);
        mob.rect = (sfIntRect) {0, 0, 512, 512};
        sfSprite_setScale(mob.sprite, (sfVector2f) {0.15, 0.15});
        mob.type = type;
    } else if (type == 2) {
    sfSprite_setTexture(mob.sprite, game->textures.mob_gost, sfTrue);
        mob.rect = (sfIntRect) {0, 0, 40, 25};
        sfSprite_setScale(mob.sprite, (sfVector2f) {1.9, 1.9});
        mob.type = type;
    }
    sfSprite_setPosition(mob.sprite, mob.pos);
    inject_mob(game, mob);
}