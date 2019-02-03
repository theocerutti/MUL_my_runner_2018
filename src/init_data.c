/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Initialise all data
*/

#include "../include/my_runner.h"

void init_all_data(data_st *dt_game, data_menu_st *dt_menu)
{
    dt_game->block_list = NULL;
    init_clock_data(dt_game);
    init_sprite_data(dt_game);
    init_player_jump_data(dt_game);
    init_background_data(dt_game);
    init_txt_data(dt_game);
    init_sound_game(dt_game);
    init_menu_data(dt_menu);
    init_menu_data2(dt_menu);
    init_menu_data3(dt_menu);
    init_menu_data4(dt_menu);
    init_menu_data5(dt_menu);
    init_menu_data6(dt_menu);
    init_menu_data7(dt_menu);
}

void init_sprite_data(data_st *data)
{
    sprite p = {672, 119, {84, 84}, 0, 255, {0, 0}, {0, 600}, 0, 0, {0}};
    sprite run = {672, 119, {84, 84}, 0, 255, {0, 0}, {0, 0}, 0, 0, {0}};
    sprite jump = {346, 133, {84, 84}, 0, 255, {0, 0}, {0, 0}, 0, 0, {0}};

    data->player = malloc(sizeof(sprite) * 3);
    init_sprite(&jump, "lib/images/player/jump_sheet.png");
    init_sprite(&run, "lib/images/player/run_sheet.png");
    init_sprite(&p, "lib/images/player/run_sheet.png");
    data->player[0] = p;
    data->player[1] = run;
    data->player[2] = jump;
}

void init_txt_data(data_st *data)
{
    score_st score = {0, {NULL, NULL, {750, 20}, sfBlack, 70}};
    txt_st game_over_txt = {NULL, NULL, {430, 300}, sfBlack, 150};
    txt_st victory_txt = {NULL, NULL, {470, 300}, sfBlack, 150};

    init_txt(&score.score_txt, "lib/font/Gourmet.otf", "0");
    init_txt(&game_over_txt, "lib/font/Gourmet.otf", "Game Over..");
    init_txt(&victory_txt, "lib/font/Gourmet.otf", "Victory !");
    data->score = score;
    data->w_l.txt = malloc(sizeof(txt_st) * 2);
    data->w_l.txt[0] = game_over_txt;
    data->w_l.txt[1] = victory_txt;
    data->w_l.state = NOTHING;
}

void init_background_data(data_st *data)
{
    sprite b1 = {4608, 1296, {1, 2304}, 0, 255, {0, 0}, {0, -450}, 0, 0, {0}};
    sprite b2 = {4608, 1296, {2, 2304}, 0, 255, {0, 0}, {0, -450}, 0, 0, {0}};
    sprite b3 = {4608, 1296, {3, 2304}, 0, 255, {0, 0}, {0, -450}, 0, 0, {0}};
    sprite b4 = {4608, 1296, {4, 2304}, 0, 255, {0, 0}, {0, -450}, 0, 0, {0}};
    sprite b5 = {6144, 1728, {8, 3072}, 0, 255, {0, 0}, {0, -640}, 0, 0, {0}};
    l_list background_list = NULL;

    init_sprite(&b1, "lib/images/background/plx-1.png");
    init_sprite(&b2, "lib/images/background/plx-2.png");
    init_sprite(&b3, "lib/images/background/plx-3.png");
    init_sprite(&b4, "lib/images/background/plx-4.png");
    init_sprite(&b5, "lib/images/full_tiles_without.png");
    background_list = push(background_list, b1);
    background_list = push(background_list, b2);
    background_list = push(background_list, b3);
    background_list = push(background_list, b4);
    background_list = push(background_list, b5);
    data->bg_list = background_list;
}

void init_clock_data(data_st *data)
{
    clock_st clock_background_anim;
    clock_st clock_player_anim;

    init_clock(&clock_background_anim);
    init_clock(&clock_player_anim);
    data->tab_clock = malloc(sizeof(clock_st) * 2);
    data->tab_clock[0] = clock_background_anim;
    data->tab_clock[1] = clock_player_anim;
}
