/*
** EPITECH PROJECT, 2021
** MY RUNNER MAIN
** File description:
** NO DESCRIPTION FOUND
*/

#include "./include/my_runner.h"
#include<time.h>

void init_game(game_t *game, char *path)
{
    srand(time(0));
    init_parallax(game);
    init_textures(game);
    init_windows(game);
    init_sprite(game);
    game->clock.clock = sfClock_create();
    game->clock_jump.clock = sfClock_create();
    game->clock_mobs.clock = sfClock_create();
    init_text(game, path);
    init_buttons(game);
    init_songs(game);
    sfMusic_play(game->sounds.menu);
    sfMusic_setVolume(game->sounds.menu, 25);
    game->score = 0;
}

int init_map(game_t *game, int ac, char **av)
{
    if (ac == 2) {
        if (check_map(av[1], game) == 84) {
            my_putstr("Error, this map could not be loaded !");
            return (84);
        } else {
            init_game(game, (av[1]));
            cheack_mobs(game);
        }
    }
    return (0);
}

int exit_general(int ac, char **av, game_t *game) {
    if (check_args(av, ac, 1, "-h")) {
        my_putstr(HELP_MESSAGE);
        return (84);
    }
    if (check_args(av, ac, 1, "-i")) {
        game->isInfinite = TRUE;
        init_game(game, ("Infinite Mode"));
        create_random_mob(game);
        return (0);
    } else if (!check_args(av, ac, 1, "-h") && !check_args(av, ac, 1, "-i")) {
        if (init_map(game, ac, av) == 84)
            return (84);
    }
    game->isInfinite = FALSE;
    return (0);
}

int main(int ac, char **av)
{
    game_t game;

    if (ac == 1) {
        my_putstr(HELP_MESSAGE);
        return (84);
    }
    void (*game_ptr[6])(game_t *) = {&loop_menu, &loop_in_game,
    &loop_pause, &loop_win, &loop_loose, &loop_close};

    if (exit_general(ac, av, &game) == 84)
        return (84);
    while (sfRenderWindow_isOpen(game.window)) {
        (*game_ptr[game.state])(&game);
    }
    close_game(&game);
    return (0);
}
