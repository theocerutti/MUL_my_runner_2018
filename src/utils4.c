/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** utils4.c
*/

#include "../include/my_runner.h"

void destroy_all_clock(data_st *data)
{
    destroy_clock(&data->tab_clock[0]);
    destroy_clock(&data->tab_clock[1]);
    free(data->tab_clock);
}

void destroy_all_sprite(data_st *data, data_menu_st *dt_menu)
{
    for (int i = 0; i < 3; i++)
        destroy_sprite(&data->player[i]);
    free(data->player);
    for (int i = 0; i < 6; i++)
        sfTexture_destroy(data->tab_t_player[i]);
    free(data->tab_t_player);
    destroy_sprite(&dt_menu->board_info);
    destroy_sprite(&dt_menu->menu_title);
    destroy_sprite(&dt_menu->b_play);
    destroy_sprite(&dt_menu->b_info);
    destroy_sprite(&dt_menu->b_setting);
    destroy_sprite(&dt_menu->b_close_info);
    destroy_sprite(&dt_menu->player_select.b_player);
    destroy_sprite(&dt_menu->b_sound);
}
