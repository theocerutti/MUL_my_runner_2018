/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Menu.c
*/

#include "../include/my_runner.h"

void destroy_sound(data_menu_st *dt_menu, data_st *dt)
{
    destroy_sfx_st(&dt_menu->sound[0]);
    destroy_sfx_st(&dt_menu->sound[1]);
    free(dt_menu->sound);
    destroy_sfx_st(&dt_menu->music);
    destroy_sfx_st(&dt->music);
    destroy_sfx_st(&dt->pick_coin);
    destroy_sfx_st(&dt->jump);
    destroy_sfx_st(&dt->run);
}

void destroy_sfx_st(sfx_st *sfx)
{
    sfMusic_destroy(sfx->music);
    sfSound_destroy(sfx->sound);
    sfSoundBuffer_destroy(sfx->buffer);
}

void destroy_sprite(sprite *s)
{
    sfSprite_destroy(s->s);
    sfTexture_destroy(s->t);
}

void destroy_txt(txt_st *txt)
{
    sfText_destroy(txt->txt);
    sfFont_destroy(txt->font);
}

void destroy_clock(clock_st *clock)
{
    sfClock_destroy(clock->clock);
}
