/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Header of my_runner
*/

#ifndef __MY_RUNNER__
#define __MY_RUNNER__

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my.h"
#include "struct.h"

#define MUSIC 11
#define SOUND 10
#define END 6
#define PICKABLE_ITEM 5
#define KILL 4
#define BOUNCE 3
#define JUMP 2
#define RUN 1
#define NOTHING -1
#define EXIT -2
#define EXIT_MENU -3

int pause_menu(sfRenderWindow *, data_menu_st *);
int open_menu(data_st *, data_menu_st *, sfRenderWindow *, int);
int click_menu(sfRenderWindow *, data_menu_st *, data_st *, int *);
void move_mouse_ui(sfRenderWindow *, data_menu_st *);
void close_open_menu(data_menu_st *, int *, sfVector2i);

int select_level(data_menu_st *, sfVector2i, int *);
void select_player(data_menu_st *, data_st *, sfVector2i);

char *read_map(map_st *, char *);
void make_map(data_st *);
void make_block(data_st *, sfVector2i, int, char const *);
void str_to_tab(map_st *, char *);
void search_block_for_make(data_st *, sfVector2i);

void launch_runner(int *, data_st *, data_menu_st *, sfRenderWindow *);
int launch_game(data_st *, data_menu_st *, sfRenderWindow *, int);

int analyse_events(sfRenderWindow *, data_st *, data_menu_st *);

void anim_sprite(sprite *);
void anim_sprite_list(l_list);

void destroy_all_sprite(data_st *, data_menu_st *);
void draw_list(sfRenderWindow *, l_list);
void destroy_txt(txt_st *);
void destroy_all(sfRenderWindow *, data_st *, data_menu_st *);
void destroy_list(l_list);
void destroy_sound(data_menu_st *, data_st *);
void destroy_sfx_st(sfx_st *);
void destroy_sprite(sprite *);
void destroy_clock(clock_st *);
void destroy_all_clock(data_st *);
void draw_all(sfRenderWindow *, data_st *);
void anim_all(data_st *);

void draw_menu(sfRenderWindow *, data_menu_st *, data_st *, int);
void anim_menu(data_st *);
void draw_tab(sfRenderWindow *, sprite *, int);
void draw_w_l(sfRenderWindow *, data_menu_st *, int);
void add_score(sfText *, int *);

void init_clock(clock_st *);
void init_sprite(sprite *, char const *);
void init_sfx(sfx_st *, char const *);
void init_txt(txt_st *, char const *, char const *);

void init_all_data(data_st *, data_menu_st *);
void init_clock_data(data_st *);
void init_sprite_data(data_st *);
void init_background_data(data_st *);
void init_txt_data(data_st *);

void init_map_data(data_st *, char *);
void init_menu_data(data_menu_st *);
void init_menu_data2(data_menu_st *);
void init_menu_data3(data_menu_st *);
void init_menu_data4(data_menu_st *);

void init_menu_data5(data_menu_st *);
void init_menu_data6(data_menu_st *);
void init_menu_data7(data_menu_st *);
void init_player_jump_data(data_st *);
void init_sound_game(data_st *);

l_list delete_list(l_list);
l_list push(l_list, sprite);
l_list pop_index(l_list, int);
void print_list(l_list);
int is_empty(l_list);

void player_jump(sprite *, int);
void put_player_state(sprite *, int);
void apply_gravity(sprite *, int *);
void apply_move_right(sprite *);
void apply_extra_move(sprite *, int *);

int is_colliding(sprite, int, int);
int look_collide(data_st *);
int collide_top(node *, int *, data_st *);
int collide_down(node *, int *, data_st *);
int collide_right(node *, int *, data_st *);

#endif
