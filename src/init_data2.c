/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Init_all_data
*/

#include "../include/my_runner.h"

void init_map_data(data_st *data, char *path_file)
{
    data->map.map = NULL;
    data->map.y = 0;
    data->map.x = 0;

    read_map(&data->map, path_file);
    data->map.map = malloc(sizeof(char *) * (data->map.y));
    for (int i = 0; i < data->map.y; i++)
        data->map.map[i] = malloc(sizeof(char) * (data->map.x + 1));
    str_to_tab(&data->map, path_file);
    make_map(data);
}

void init_menu_data(data_menu_st *data_menu)
{
    sprite board_info = {882, 695, {882, 882}, 0, 255, {0, 0}, {340, 60}, \
    0, 0, {0}};
    sprite menu_title = {650, 315, {650, 650}, 0, 240, {0, 0}, {400, 100}, \
    0, 0, {0}};
    sfx_st music_menu = {MUSIC, 100, 0, 0, 0};
    sfx_st sound_click_ui = {SOUND, 100, 0, 0, 0};
    sfx_st sound_mouse_ui = {SOUND, 100, 0, 0, 0};

    init_sprite(&board_info, "lib/images/menu/board_info.png");
    init_sprite(&menu_title, "lib/images/menu/menu_title.png");
    init_sfx(&music_menu, "lib/music/menu_music.ogg");
    init_sfx(&sound_mouse_ui, "lib/sound/sfx_mouse_ui.ogg");
    init_sfx(&sound_click_ui, "lib/sound/sfx_click_select_ui.ogg");
    data_menu->board_info = board_info;
    data_menu->menu_title = menu_title;
    data_menu->sound = malloc(sizeof(sfx_st) * 2);
    data_menu->sound[0] = sound_click_ui;
    data_menu->sound[1] = sound_mouse_ui;
    data_menu->music = music_menu;
}

void init_menu_data2(data_menu_st *data_menu)
{
    sprite b_play = {193, 194, {193, 193}, 0, 255, {0, 0}, {650, 500}, \
    0, 0, {0}};
    sprite b_sound = {214, 108, {107, 107}, 0, 255, {0, 0}, {30, 730}, \
    0, 0, {0}};
    sprite b_setting = {107, 108, {107, 107}, 0, 255, {0, 0}, {1400, 30}, \
    0, 0, {0}};
    sprite b_player = {107, 108, {107, 107}, 0, 255, {0, 0}, {1400, 30}, \
    0, 0, {0}};
    sprite nfo = {107, 108, {107, 107}, 0, 255, {0, 0}, {30, 30}, 0, 0, {0}};

    init_sprite(&b_play, "lib/images/menu/button_play.png");
    init_sprite(&b_sound, "lib/images/menu/button_sound_on_off.png");
    init_sprite(&b_setting, "lib/images/menu/button_setting.png");
    init_sprite(&nfo, "lib/images/menu/button_info.png");
    init_sprite(&b_player, "lib/images/menu/button_player.png");
    data_menu->b_play = b_play;
    data_menu->b_sound = b_sound;
    data_menu->b_setting = b_setting;
    data_menu->player_select.b_player = b_player;
    data_menu->b_info = nfo;
}

void init_menu_data3(data_menu_st *data_menu)
{
    char path[] = "level/level";
    int i = 0;
    sprite close = {75, 74, {75, 75}, 0, 255, {0, 0}, {1000, 100}, 0, 0, {0}};
    sprite board_lvl = {654, 806, {654, 654}, 0, 255, {0, 0}, {430, 30}, \
    0, 0, {0}};

    data_menu->menu_level.path_level = malloc(sizeof(char) * 100000);
    for (i = 0; path[i] != '\0'; i++)
        data_menu->menu_level.path_level[i] = path[i];
    data_menu->menu_level.path_level[i] = '\0';
    init_sprite(&board_lvl, "lib/images/menu/level/board_select_level.png");
    init_sprite(&close, "lib/images/menu/b_close.png");
    data_menu->menu_level.b_close = close;
    data_menu->menu_level.board = board_lvl;
}

void init_menu_data4(data_menu_st *data_menu)
{
    sprite b_close_player = {75, 74, {75, 75}, 0, 255, {0, 0}, {980, 225}, \
    0, 0, {0}};
    sprite board_player = {649, 476, {649, 649}, 0, 255, {0, 0}, {450, 200}, \
    0, 0, {0}};
    sprite b_p_normal = {672, 119, {84, 84}, 0, 75, {0, 0}, {580, 320}, \
    0, 0, {0}};
    sprite b_p_green = {672, 119, {84, 84}, 0, 75, {0, 0}, {730, 320}, \
    0, 0, {0}};

    init_sprite(&b_close_player, "lib/images/menu/b_close.png");
    init_sprite(&board_player, "lib/images/menu/board_player_selection.png");
    init_sprite(&b_p_normal, "lib/images/player/run_sheet.png");
    init_sprite(&b_p_green, "lib/images/player/run_sheet_green.png");
    data_menu->player_select.b = malloc(sizeof(sprite) * 6);
    data_menu->player_select.b[0] = b_p_normal;
    data_menu->player_select.b[1] = b_p_green;
    data_menu->player_select.b_close = b_close_player;
    data_menu->player_select.board = board_player;
}
