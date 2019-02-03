/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Collide.h
*/

#include "../include/my_runner.h"

int is_colliding(sprite block, int x, int y)
{
    if (x >= block.pos.x && x <= block.pos.x + block.rect.width \
    && y >= block.pos.y && y <= block.pos.y + block.rect.height)
        return (1);
    return (0);
}

int look_collide(data_st *d)
{
    node *b = d->block_list;
    int ctn = 0;
    sprite p = d->player[0];

    for (int i = 0; b != NULL; i++, b = b->next) {
        if (is_colliding(b->obj, p.pos.x + p.rect.width, p.pos.y + p.height /
        2) || is_colliding(b->obj, p.pos.x + p.rect.width, p.pos.y + p.height
        - 25) || is_colliding(b->obj, p.pos.x + p.rect.width, p.pos.y + 25))
            ctn = collide_right(b, &i, d);
        else if (is_colliding(b->obj, p.pos.x + p.rect.width / 2, \
        p.pos.y) || is_colliding(b->obj, p.pos.x + p.rect.width, \
        p.pos.y) || is_colliding(b->obj, p.pos.x, p.pos.y))
            ctn = collide_down(b, &i, d);
        if (is_colliding(b->obj, p.pos.x + p.rect.width, p.pos.y +
        p.height) || is_colliding(b->obj, p.pos.x + p.rect.width / 2, p.pos.y
        + p.height) || is_colliding(b->obj, p.pos.x, p.pos.y + p.height))
            ctn = collide_top(b, &i, d);
    }
    return (ctn);
}

int collide_top(node *b, int *index, data_st *d)
{
    if (b->obj.state == NOTHING || b->obj.state == BOUNCE) {
        d->player[0].pos.y = b->obj.pos.y - d->player[0].height - 20;
        if (b->obj.state == BOUNCE) {
            sfSound_play(d->jump.sound);
            d->player[0].v.y = -30;
        }
    } else if (b->obj.state == PICKABLE_ITEM) {
        sfSound_play(d->pick_coin.sound);
        d->block_list = pop_index(d->block_list, *index);
        *index -= 1;
        add_score(d->score.score_txt.txt, &d->score.score);
    }
    if (b->obj.state == KILL) {
        d->w_l.state = 0;
    }
    return (0);
}

int collide_down(node *b, int *index, data_st *d)
{
    if (b->obj.state == NOTHING || b->obj.state == BOUNCE) {
        d->player[0].pos.y = b->obj.pos.y + b->obj.height + 20;
    } else if (b->obj.state == PICKABLE_ITEM) {
        sfSound_play(d->pick_coin.sound);
        d->block_list = pop_index(d->block_list, *index);
        *index -= 1;
        add_score(d->score.score_txt.txt, &d->score.score);
    }
    if (b->obj.state == KILL) {
        d->w_l.state = 0;
    }
    return (0);
}

int collide_right(node *b, int *index, data_st *d)
{
    if (b->obj.state == NOTHING || b->obj.state == BOUNCE) {
        d->player[0].pos.x = b->obj.pos.x - d->player[0].rect.width;
    } else if (b->obj.state == PICKABLE_ITEM) {
        sfSound_play(d->pick_coin.sound);
        d->block_list = pop_index(d->block_list, *index);
        *index -= 1;
        add_score(d->score.score_txt.txt, &d->score.score);
    }
    if (b->obj.state == KILL) {
        d->w_l.state = 0;
    } else if (b->obj.state == END) {
        d->w_l.state = 1;
    }
    return (0);
}
