/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Menu.c
*/

#include "../include/my_runner.h"

int pause_menu(sfRenderWindow *w, data_menu_st *dm)
{
    sfEvent event;

    while (sfKeyboard_isKeyPressed(sfKeySpace) != sfTrue) {
        while (sfRenderWindow_pollEvent(w, &event)) {
            sfRenderWindow_display(w);
            sfRenderWindow_drawSprite(w, dm->pause_menu.s, NULL);
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(w);
                return (EXIT);
            }
            if (event.type == sfEvtKeyReleased && \
            event.key.code == sfKeyA)
                return (EXIT_MENU);
        }
    }
    return (0);
}

void close_open_menu(data_menu_st *dm, int *m_bool, sfVector2i pos_m)
{
    if ((is_colliding(dm->b_info, pos_m.x, pos_m.y)
    || is_colliding(dm->b_close_info, pos_m.x, pos_m.y))
    && (*m_bool == 1 || *m_bool == 0)) {
        sfSound_play(dm->sound[0].sound);
        *m_bool = (*m_bool != 1) ? 1 : 0;
    }
    if ((is_colliding(dm->b_play, pos_m.x, pos_m.y)
    || is_colliding(dm->menu_level.b_close, pos_m.x, pos_m.y))
    && (*m_bool == 2 || *m_bool == 0)) {
        sfSound_play(dm->sound[0].sound);
        *m_bool = (*m_bool != 2) ? 2 : 0;
    }
    if ((is_colliding(dm->player_select.b_player, pos_m.x, pos_m.y)
    || is_colliding(dm->player_select.b_close, pos_m.x, pos_m.y))
    && (*m_bool == 3 || *m_bool == 0)) {
        sfSound_play(dm->sound[0].sound);
        *m_bool = (*m_bool != 3) ? 3 : 0;
    }
}

void move_mouse_ui(sfRenderWindow *w, data_menu_st *dm)
{
    sfVector2i pos_m = sfMouse_getPositionRenderWindow(w);

    if (is_colliding(dm->b_play, pos_m.x, pos_m.y) \
    || is_colliding(dm->b_sound, pos_m.x, pos_m.y) \
    || is_colliding(dm->player_select.b_player, pos_m.x, pos_m.y) \
    || is_colliding(dm->b_info, pos_m.x, pos_m.y)) {
        sfSound_play(dm->sound[1].sound);
    }
}

int click_menu(sfRenderWindow *w, data_menu_st *dm, data_st *dt, int *m_bool)
{
    sfVector2i pos_m = sfMouse_getPositionRenderWindow(w);
    int ctn = 1;

    if (*m_bool == 2)
        ctn = select_level(dm, pos_m, m_bool);
    else if (*m_bool == 3)
        select_player(dm, dt, pos_m);
    if (is_colliding(dm->b_sound, pos_m.x, pos_m.y)) {
        dm->music.volume = (dm->music.volume == 0) ? 100 : 0;
        dt->music.volume = (dt->music.volume == 0) ? 100 : 0;
        sfSound_play(dm->sound[0].sound);
        anim_sprite(&dm->b_sound);
        sfMusic_setVolume(dm->music.music, dm->music.volume);
        sfMusic_setVolume(dt->music.music, dt->music.volume);
    }
    close_open_menu(dm, m_bool, pos_m);
    return (ctn);
}

int open_menu(data_st *dt, data_menu_st *dm, sfRenderWindow *w, int ctn)
{
    sfEvent event;
    static int m_bool = 0;

    while (sfRenderWindow_pollEvent(w, &event)) {
        if (event.type == sfEvtClosed)
            return (EXIT);
        if (event.type == sfEvtMouseButtonPressed)
            ctn = click_menu(w, dm, dt, &m_bool);
        if (event.type == sfEvtMouseMoved)
            move_mouse_ui(w, dm);
    }
    anim_menu(dt);
    draw_menu(w, dm, dt, m_bool);
    return (ctn);
}
