/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** init_data3
*/

#include "../include/my_runner.h"

void init_menu_data5(data_menu_st *data_menu)
{
    sprite close = {75, 74, {75, 75}, 0, 255, {0, 0}, {1100, 100}, 0, 0, {0}};
    sprite pr_orange = {672, 119, {84, 84}, 0, 75, {0, 0}, {880, 320}, \
    0, 0, {0}};
    sprite pr_green_fluo = {672, 119, {84, 84}, 0, 75, {0, 0}, {580, 450}, \
    0, 0, {0}};
    sprite pr_blue = {672, 119, {84, 84}, 0, 75, {0, 0}, {730, 450}, \
    0, 0, {0}};
    sprite pr_white = {672, 119, {84, 84}, 0, 75, {0, 0}, {880, 450}, \
    0, 0, {0}};

    init_sprite(&pr_orange, "lib/images/player/run_sheet_orange.png");
    init_sprite(&pr_green_fluo, "lib/images/player/run_sheet_green_fluo.png");
    init_sprite(&pr_blue, "lib/images/player/run_sheet_blue.png");
    init_sprite(&pr_white, "lib/images/player/run_sheet_white.png");
    init_sprite(&close, "lib/images/menu/b_close.png");
    data_menu->player_select.b[2] = pr_orange;
    data_menu->player_select.b[3] = pr_green_fluo;
    data_menu->player_select.b[4] = pr_blue;
    data_menu->player_select.b[5] = pr_white;
    data_menu->b_close_info = close;
}

void init_player_jump_data(data_st *data)
{
    sfTexture *pj_normal = sfTexture_createFromFile \
    ("lib/images/player/jump_sheet.png", NULL);
    sfTexture *pj_green = sfTexture_createFromFile \
    ("lib/images/player/jump_sheet_green.png", NULL);
    sfTexture *pj_orange = sfTexture_createFromFile \
    ("lib/images/player/jump_sheet_orange.png", NULL);
    sfTexture *pj_green_fluo = sfTexture_createFromFile \
    ("lib/images/player/jump_sheet_green_fluo.png", NULL);
    sfTexture *pj_blue = sfTexture_createFromFile \
    ("lib/images/player/jump_sheet_blue.png", NULL);
    sfTexture *pj_white = sfTexture_createFromFile \
    ("lib/images/player/jump_sheet_white.png", NULL);

    data->tab_t_player = malloc(sizeof(sfTexture *) * 6);
    data->tab_t_player[0] = pj_normal;
    data->tab_t_player[1] = pj_green;
    data->tab_t_player[2] = pj_orange;
    data->tab_t_player[3] = pj_green_fluo;
    data->tab_t_player[4] = pj_blue;
    data->tab_t_player[5] = pj_white;
}

void init_menu_data6(data_menu_st *data_menu)
{
    sprite l1 = {130, 130, {130, 130}, 0, 255, {0, 0}, {530, 230}, 0, 0, {0}};
    sprite l2 = {130, 130, {130, 130}, 0, 255, {0, 0}, {680, 230}, 0, 0, {0}};
    sprite l3 = {130, 130, {130, 130}, 0, 255, {0, 0}, {830, 230}, 0, 0, {0}};
    sprite l4 = {130, 130, {130, 130}, 0, 255, {0, 0}, {530, 380}, 0, 0, {0}};
    sprite l5 = {130, 130, {130, 130}, 0, 255, {0, 0}, {680, 380}, 0, 0, {0}};
    sprite l6 = {130, 130, {130, 130}, 0, 255, {0, 0}, {830, 380}, 0, 0, {0}};

    init_sprite(&l1, "lib/images/menu/level/lv-1.png");
    init_sprite(&l2, "lib/images/menu/level/lv-2.png");
    init_sprite(&l3, "lib/images/menu/level/lv-3.png");
    init_sprite(&l4, "lib/images/menu/level/lv-4.png");
    init_sprite(&l5, "lib/images/menu/level/lv-5.png");
    init_sprite(&l6, "lib/images/menu/level/lv-6.png");
    data_menu->menu_level.level = malloc(sizeof(sprite) * 9);
    data_menu->menu_level.level[0] = l1;
    data_menu->menu_level.level[1] = l2;
    data_menu->menu_level.level[2] = l3;
    data_menu->menu_level.level[3] = l4;
    data_menu->menu_level.level[4] = l5;
    data_menu->menu_level.level[5] = l6;
}

void init_menu_data7(data_menu_st *data_menu)
{
    sprite l7 = {130, 130, {130, 130}, 0, 255, {0, 0}, {530, 530}, 0, 0, {0}};
    sprite l8 = {130, 130, {130, 130}, 0, 255, {0, 0}, {680, 530}, 0, 0, {0}};
    sprite l9 = {130, 130, {130, 130}, 0, 255, {0, 0}, {830, 530}, 0, 0, {0}};
    sprite pause_menu = {646, 523, {646, 646}, 0, 255, {0, 0}, {450, 150}, \
    0, 0, {0}};

    init_sprite(&l7, "lib/images/menu/level/lv-7.png");
    init_sprite(&l8, "lib/images/menu/level/lv-8.png");
    init_sprite(&l9, "lib/images/menu/level/lv-9.png");
    init_sprite(&pause_menu, "lib/images/menu/pause_menu.png");
    data_menu->pause_menu = pause_menu;
    data_menu->menu_level.level[6] = l7;
    data_menu->menu_level.level[7] = l8;
    data_menu->menu_level.level[8] = l9;
}

void init_sound_game(data_st *data)
{
    sfx_st music = {MUSIC, 70, 0, 0, 0};
    sfx_st pick_coin = {SOUND, 100, 0, 0, 0};
    sfx_st jump = {SOUND, 100, 0, 0, 0};
    sfx_st run = {SOUND, 100, 0, 0, 0};

    init_sfx(&music, "lib/music/main_music.ogg");
    init_sfx(&pick_coin, "lib/sound/sfx_coin_double7.ogg");
    init_sfx(&jump, "lib/sound/sfx_jump.ogg");
    init_sfx(&run, "lib/sound/sfx_run.ogg");
    data->jump = jump;
    data->music = music;
    data->pick_coin = pick_coin;
    data->run = run;
}
