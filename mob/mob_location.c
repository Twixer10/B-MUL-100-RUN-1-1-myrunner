/*
** EPITECH PROJECT, 2021
** MOB LOCATION
** File description:
** mob_location
*/

#include "../include/my_runner.h"

int my_random(int min, int max)
{
    return ((rand() % (max - min + 1)) + min);
}

void randomise_location(mob_t *mob)
{
    mob->pos.x += 6500;
    mob->pos.y = (mob->type == 2?12*52:13*56);
    sfSprite_setPosition(mob->sprite, mob->pos);
}

void create_random_mob(game_t *game)
{
    game->map.all_mobs = 13;
    game->map.all_mobs_loaded = 0;
    game->mobs = malloc(sizeof(mob_t) * 13);
    create_mob(game, 1, 700, 13*56);
    create_mob(game, my_random(1, 2), 1400, 13*56);
    create_mob(game, my_random(1, 2), 1900, 13*56);
    create_mob(game, my_random(1, 2), 2400, 13*56);
    create_mob(game, my_random(1, 2), 2800, 13*56);
    create_mob(game, my_random(1, 2), 3200, 13*56);
    create_mob(game, my_random(1, 2), 3800, 13*56);
    create_mob(game, my_random(1, 2), 4200, 13*56);
    create_mob(game, my_random(1, 2), 4800, 13*56);
    create_mob(game, my_random(1, 2), 5300, 13*56);
    create_mob(game, my_random(1, 2), 5700, 13*56);
    create_mob(game, my_random(1, 2), 6000, 13*56);
    create_mob(game, 2, 6400, 13*56);
}

void reload_infinite_mob(game_t *game)
{
    for (int i = 0; i < 12; i++) {
        sfSprite_destroy(game->mobs[i].sprite);
    }
    create_random_mob(game);
}

