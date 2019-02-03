/*
** EPITECH PROJECT, 2018
** Header of struct
** File description:
** Header of struct
*/

typedef struct sprite {
    int width;
    int height;
    int offset[2];
    int state;
    sfUint8 alpha;
    sfVector2f v;
    sfVector2f pos;
    sfTexture *t;
    sfSprite *s;
    sfIntRect rect;
} sprite;

typedef struct node {
    sprite obj;
    struct node *next;
} node;
typedef node *l_list;

typedef struct txt_st {
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
    int size;
} txt_st;

typedef struct clock_st {
    sfClock *clock;
    sfTime time;
    float s;
} clock_st;

typedef struct map_st {
    char **map;
    int x;
    int y;
} map_st;

typedef struct sfx_st {
    int type;
    int volume;
    sfSoundBuffer *buffer;
    sfSound *sound;
    sfMusic *music;
} sfx_st;

typedef struct score_st {
    int score;
    txt_st score_txt;
} score_st;

typedef struct block_list {
    sprite *list;
    int length;
} block_list;

typedef struct level_menu_st {
    sprite *level;
    char *path_level;
    sprite b_close;
    sprite board;
} level_menu_st;

typedef struct menu_st {
    sprite *b;
    sprite b_close;
    sprite board;
    sprite b_player;
} menu_st;

typedef struct win_lose_st {
    txt_st *txt;
    int state;
} win_lose_st;

typedef struct data_menu_st {
    level_menu_st menu_level;
    sprite pause_menu;
    menu_st player_select;
    sprite board_info;
    sprite menu_title;
    sprite b_play;
    sprite b_sound;
    sprite b_setting;
    sprite b_info;
    sprite b_close_info;
    sfx_st music;
    sfx_st *sound;
} data_menu_st;

typedef struct data_st {
    sprite *player;
    sfTexture **tab_t_player;
    sfx_st music;
    sfx_st jump;
    sfx_st run;
    sfx_st pick_coin;
    score_st score;
    win_lose_st w_l;
    int gravity;
    l_list block_list;
    l_list bg_list;
    clock_st *tab_clock;
    map_st map;
} data_st;
