/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Initialise game object
*/

#include "../include/my_runner.h"

void draw_menu(sfRenderWindow *w, data_menu_st *dm, data_st *dt, int m_bool)
{
    sfColor bg_color = {174, 222, 203, 255};

    sfRenderWindow_clear(w, bg_color);
    draw_list(w, dt->bg_list);
    sfRenderWindow_drawSprite(w, dm->menu_title.s, NULL);
    sfRenderWindow_drawSprite(w, dm->b_play.s, NULL);
    sfRenderWindow_drawSprite(w, dm->b_sound.s, NULL);
    sfRenderWindow_drawSprite(w, dm->player_select.b_player.s, NULL);
    sfRenderWindow_drawSprite(w, dm->b_info.s, NULL);
    draw_w_l(w, dm, m_bool);
    sfRenderWindow_display(w);
}

void draw_w_l(sfRenderWindow *w, data_menu_st *dm, int m_bool)
{
    if (m_bool == 1) {
        sfRenderWindow_drawSprite(w, dm->board_info.s, NULL);
        sfRenderWindow_drawSprite(w, dm->b_close_info.s, NULL);
    } else if (m_bool == 2) {
        sfRenderWindow_drawSprite(w, dm->menu_level.board.s, NULL);
        sfRenderWindow_drawSprite(w, dm->menu_level.b_close.s, NULL);
        draw_tab(w, dm->menu_level.level, 9);
    }
    if (m_bool == 3) {
        sfRenderWindow_drawSprite(w, dm->player_select.board.s, NULL);
        sfRenderWindow_drawSprite(w, dm->player_select.b_close.s, NULL);
        draw_tab(w, dm->player_select.b, 6);
    }
}

void anim_menu(data_st *dt)
{
    anim_sprite_list(dt->bg_list);
}

void draw_tab(sfRenderWindow *w, sprite *s_tab, int length)
{
    for (int i = 0; i < length; i++)
        sfRenderWindow_drawSprite(w, s_tab[i].s, NULL);
}

void add_score(sfText *txt, int *score)
{
    *score += 1;
    sfText_setString(txt, my_itoa(*score));
}
