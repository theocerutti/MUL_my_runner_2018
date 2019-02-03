/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Initialise launch game
*/

#include "../include/my_runner.h"

void launch_runner(int *continu, data_st *data, data_menu_st *data_menu, \
sfRenderWindow *window)
{
    for (int turn = 0; *continu != EXIT_MENU; turn++) {
        if (turn >= 1)
            destroy_sound(data_menu, data);
        init_all_data(data, data_menu);
        sfMusic_play(data_menu->music.music);
        *continu = 1;
        while (*continu == 1)
            *continu = open_menu(data, data_menu, window, *continu);
        sfMusic_stop(data_menu->music.music);
        sfMusic_play(data->music.music);
        *continu = launch_game(data, data_menu, window, *continu);
        sfMusic_stop(data->music.music);
    }
}

int launch_game(data_st *dt, data_menu_st *dm, sfRenderWindow *w, int ctn)
{
    if (ctn != EXIT) {
        init_map_data(dt, dm->menu_level.path_level);
        while (sfRenderWindow_isOpen(w) && ctn != EXIT) {
            ctn = analyse_events(w, dt, dm);
            if (dt->player[0].pos.x < -100)
                dt->w_l.state = 0;
            if (ctn == EXIT_MENU)
                return (0);
            if (dt->w_l.state != -1)
                dt->player[0].pos.x = -100;
            else if (dt->w_l.state == -1)
                ctn = look_collide(dt);
            apply_extra_move(&dt->player[0], &dt->gravity);
            anim_all(dt);
            draw_all(w, dt);
        }
    }
    return (EXIT_MENU);
}
