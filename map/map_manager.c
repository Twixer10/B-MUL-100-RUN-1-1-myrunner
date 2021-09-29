/*
** EPITECH PROJECT, 2021
** MAP MANAGER
** File description:
** NO DSC FND
*/

#include "../include/my_runner.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int reload_mobs(game_t *game)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int o = 0;
    mob_t mob;

    while (i != 1213) {
        if (game->map.map[i] == '1' || game->map.map[i] == '2') {
            x = i-(((int) i/81)) * 81;
            y = (int) i/81;
            mob = game->mobs[o++];
            mob.pos = (sfVector2f) {x * 100,
            y * (game->map.map[i] == '1'?56:52)};
            sfSprite_setPosition(mob.sprite, mob.pos);
        }
        i++;
    }
    return (0);
}

int load_mobs(game_t *game)
{
    int i = 0;
    int x = 0;
    int y = 0;

    game->mobs = malloc(sizeof(mob_t) * game->map.all_mobs);

    while (i != 1213) {
        if (game->map.map[i] == '1' || game->map.map[i] == '2') {
            x = i-(((int) i/81)) * 81;
            y = (int) i/81;
                create_mob(game, get_one_nbr(game->map.map[i]), x * 100,
            y * (game->map.map[i] == '1'?56:52));
        }
        i++;
    }
    return (0);
}

int cheack_mobs(game_t *game)
{
    int i = 0;

    game->map.all_mobs = 0;
    while (i != 1213) {
        if (game->map.map[i] == '1' || game->map.map[i] == '2') {
            game->map.all_mobs++;
        }
        i++;
    }
    game->map.all_mobs_loaded = 0;
    return (load_mobs(game));
}

int analyse_map(game_t *game)
{
    int i = 0;

    for (int i = 0; i < 80; i++) {
        if (game->map.map[i] != '.')
            return (84);
        if (game->map.map[1213 - i] != '.')
            return (84);
    }
    while (i != 1213) {
        if (game->map.map[i] != '.' && game->map.map[i] != ' ' &&
        game->map.map[i] != '1' && game->map.map[i] != '2' &&
        game->map.map[i] != '\n' && game->map.map[i] != '\0')
            return (84);
        i++;
    }
    return (0);
}

int check_map(char *path, game_t *game)
{
    int file = open(path, O_RDONLY);
    int i = 0;

    game->map.map = malloc(81*15 * sizeof(char *));
    while (i < 15) {
        read(file, game->map.map, 81*15);
        i++;
    }
    close(file);
    return (analyse_map(game));
}