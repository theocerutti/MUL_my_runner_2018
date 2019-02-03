/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Handle player
*/

#include "../include/my_runner.h"

void player_jump(sprite *player, int offset)
{
    player[0].v.y = offset;
    player[0].state = 1;
    put_player_state(player, JUMP);
}

void put_player_state(sprite *player, int index)
{
    player[0].height = player[index].height;
    player[0].width = player[index].width;
    player[0].offset[0] = player[index].offset[0];
    player[0].offset[1] = player[index].offset[1];
    sfSprite_setTexture(player[0].s, player[index].t, sfTrue);
    sfSprite_setTextureRect(player[0].s, player[index].rect);
}

void apply_move_right(sprite *player)
{
    if (player->pos.x <= 200)
        player->pos.x += 2;
}

void apply_gravity(sprite *player, int *gravity)
{
    *gravity = 2;
    player->v.y += *gravity;
    if (player->v.y >= 20)
        player->v.y = 20;
    player->pos.y += player->v.y;
    if (player->state == 1 && player->v.y == 20) {
        put_player_state(player, RUN);
        player->state = 0;
    }
    if (player->pos.y >= 599)
        player->pos.y = 599;
    sfSprite_setPosition(player->s, player->pos);
}

void apply_extra_move(sprite *player, int *gravity)
{
    apply_gravity(player, gravity);
    apply_move_right(player);
}
