/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Utils my_runner
*/

#include "../include/my_runner.h"

void anim_all(data_st *d)
{
    node *block = d->block_list;

    d->tab_clock[0].time = sfClock_getElapsedTime(d->tab_clock[0].clock);
    d->tab_clock[0].s = d->tab_clock[0].time.microseconds / 1000000.0;
    d->tab_clock[1].time = sfClock_getElapsedTime(d->tab_clock[1].clock);
    d->tab_clock[1].s = d->tab_clock[1].time.microseconds / 1000000.0;
    if (d->tab_clock[0].s > 0.017) {
        anim_sprite_list(d->bg_list);
        sfClock_restart(d->tab_clock[0].clock);
    }
    if (d->tab_clock[1].s > 0.1) {
        anim_sprite(&d->player[0]);
        while (block != NULL) {
            if (block->obj.state == PICKABLE_ITEM)
                anim_sprite(&block->obj);
            block = block->next;
        }
        sfClock_restart(d->tab_clock[1].clock);
    }
}

void draw_all(sfRenderWindow *window, data_st *data)
{
    sfColor bg_color = {174, 222, 203, 255};
    node *block = data->block_list;

    sfRenderWindow_clear(window, bg_color);
    draw_list(window, data->bg_list);
    sfRenderWindow_drawSprite(window, data->player[0].s, NULL);
    while (block != NULL) {
        block->obj.pos.x -= 6;
        sfSprite_setPosition(block->obj.s, block->obj.pos);
        sfRenderWindow_drawSprite(window, block->obj.s, NULL);
        block = block->next;
    }
    sfRenderWindow_drawText(window, data->score.score_txt.txt, NULL);
    if (data->w_l.state == 0)
        sfRenderWindow_drawText(window, data->w_l.txt[0].txt, NULL);
    else if (data->w_l.state == 1)
        sfRenderWindow_drawText(window, data->w_l.txt[1].txt, NULL);
    sfRenderWindow_display(window);
}

void draw_list(sfRenderWindow *window, l_list list)
{
    while (list != NULL) {
        sfRenderWindow_drawSprite(window, list->obj.s, NULL);
        list = list->next;
    }
}

void destroy_all(sfRenderWindow *window, data_st *data, data_menu_st *dt_menu)
{
    destroy_all_sprite(data, dt_menu);
    destroy_list(data->bg_list);
    destroy_list(data->block_list);
    destroy_sound(dt_menu, data);
    destroy_all_clock(data);
    destroy_txt(&data->w_l.txt[0]);
    destroy_txt(&data->w_l.txt[1]);
    free(data->w_l.txt);
    destroy_txt(&data->score.score_txt);
    sfRenderWindow_destroy(window);
}

void destroy_list(l_list list)
{
    while (list != NULL) {
        destroy_sprite(&list->obj);
        list = list->next;
    }
}
