/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Initialise game object
*/

#include "../include/my_runner.h"

void select_player(data_menu_st *dm, data_st *dt, sfVector2i pos_m)
{
    sfColor sf_wmid = {255, 255, 255, 75};

    for (int i = 0; i < 6; i++) {
        if (is_colliding(dm->player_select.b[i], pos_m.x, pos_m.y)) {
            for (int i = 0; i < 6; i++)
                sfSprite_setColor(dm->player_select.b[i].s, sf_wmid);
            sfSound_play(dm->sound[0].sound);
            sfSprite_setColor(dm->player_select.b[i].s, sfWhite);
            dt->player[0].t = sfTexture_copy(dm->player_select.b[i].t);
            dt->player[1].t = sfTexture_copy(dm->player_select.b[i].t);
            dt->player[2].t = sfTexture_copy(dt->tab_t_player[i]);
            sfSprite_setTexture(dt->player[0].s, dt->player[0].t, sfTrue);
            sfSprite_setTexture(dt->player[1].s, dt->player[1].t, sfTrue);
            sfSprite_setTexture(dt->player[2].s, dt->player[2].t, sfTrue);
        }
    }
}

int select_level(data_menu_st *dm, sfVector2i pos_m, int *m_bool)
{
    if (is_colliding(dm->menu_level.b_close, pos_m.x, pos_m.y)) {
        sfSound_play(dm->sound[0].sound);
        *m_bool = (*m_bool == 2) ? 2 : 0;
    }
    for (int i = 0; i < 9; i++) {
        if (is_colliding(dm->menu_level.level[i], pos_m.x, pos_m.y)) {
            sfSound_play(dm->sound[0].sound);
            my_strcat(dm->menu_level.path_level, my_itoa(i + 1));
            *m_bool = 0;
            return (0);
        }
    }
    return (1);
}
