/*
** EPITECH PROJECT, 2021
** CHARACTER MANAGER
** File description:
** NODESCFOUND
*/

#include "../include/my_runner.h"

sfFloatRect get_box(sfSprite *sp)
{
    sfFloatRect rect =  sfSprite_getGlobalBounds(sp);
    rect.height -= 35;
    rect.width -= 35;
    rect.top -= 35;
    rect.left -= 35;
    return (rect);
}

void check_colision(game_t *game)
{
    mob_t mob;
    sfFloatRect rect;
    sfFloatRect rect2;

    for (int i = 0; i < game->map.all_mobs_loaded; i++) {
        mob = game->mobs[i];
        rect = get_box(game->character.sprite);
        rect2 = get_box(mob.sprite);

    if (sfFloatRect_contains(&rect, rect2.left, rect2.top) ||
        sfFloatRect_contains(&rect, rect2.left + rect2.width, rect2.top) ||
        sfFloatRect_contains(&rect, rect2.left, rect2.top + rect2.height) ||
        sfFloatRect_contains(&rect, rect2.left + rect2.width,
                rect2.height + rect2.top)) {
                    dead(game);
                    sfMusic_stop(game->sounds.game);
                    game->state = LOOSE;
                }
    }
}

void animate_jump(game_t *game)
{
    game->clock.time = sfClock_getElapsedTime(game->clock.clock);
    game->clock.seconds = game->clock.time.microseconds / 1000000.0;
    if (game->clock.seconds > 0.01) {
        if (game->character.pos.y <= 660 && game->character.pos.y > 500 &&
            game->character.is_juping) {
                game->character.pos.y -= (game->character.pos.y / 45);
                (game->character.pos.y <= 500?game->character.is_juping = FALSE:
                0);
        } else if (game->character.pos.y < 660 && !game->character.is_juping) {
            game->character.pos.y += (game->character.pos.y / 60);
        }
    }
    if (game->character.pos.y > 660)
        game->character.pos.y = 660;
    sfSprite_setPosition(game->character.sprite, game->character.pos);
}

void display_character(game_t *game)
{
    animate_jump(game);
    game->clock.time = sfClock_getElapsedTime(game->clock.clock);
    game->clock.seconds = game->clock.time.microseconds / 1000000.0;
    if (game->clock.seconds > 0.05) {
        if (!game->character.is_juping) {
            move_rect(&game->character.rect, 587, 5870);
            sfClock_restart(game->clock.clock);
        }
    }
    sfSprite_setPosition(game->character.sprite, game->character.pos);
    sfSprite_setTextureRect(game->character.sprite, game->character.rect);
    sfRenderWindow_drawSprite(game->window, game->character.sprite, NULL);
    check_colision(game);
    game->score++;
}

void jump(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeySpace) {
            if (game->character.pos.y == 660) {
                game->character.is_juping = TRUE;
                sfSound_play(game->sounds.jump);
            }
        }
    }
}