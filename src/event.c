/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Event my_runner
*/

#include "../include/my_runner.h"

int analyse_events(sfRenderWindow *window, data_st *dt, data_menu_st *dm)
{
    sfEvent event;
    int ctn = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            ctn = pause_menu(window, dm);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace \
        && dt->player[0].v.y == 20 && dt->w_l.state == -1)
            player_jump(dt->player, -30);
        if (sfKeyboard_isKeyPressed(sfKeyA))
            return (EXIT_MENU);
    }
    return (ctn);
}
