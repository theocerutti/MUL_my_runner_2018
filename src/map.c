/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** Handle map and construct it
*/

#include "../include/my_runner.h"

char *read_map(map_st *map, char *buffer)
{
    int map_file;
    int size = 0;
    int size_map_x = 0;

    map_file = open(buffer, O_RDONLY);
    for (char c; read(map_file, &c, 1) != '\0'; size++, size_map_x++) {
        if (size_map_x >= map->x && c == '\n') {
            map->x = size_map_x;
            size_map_x = 0;
        }
        if (c == '\n')
            map->y += 1;
        buffer[size] = c;
    }
    buffer[size] = '\0';
    map->x += 1;
    close(map_file);
    return (buffer);
}

void str_to_tab(map_st *map, char *buffer)
{
    int j = 0;
    int index = 0;
    char c;

    for (int i = 0; buffer[i] != '\0'; i++) {
        c = buffer[i];
        map->map[j][index] = c;
        index += 1;
        if (buffer[i] == '\n') {
            map->map[j][index] = '\0';
            j += 1;
            index = 0;
        }
    }
}

void make_block(data_st *data, sfVector2i pos, int state, char const *path)
{
    sprite new_block = {64, 64, {64, 64}, state, \
    255, {0, 0}, {(float)pos.x * 64, (float)pos.y * 64 + 15}, 0, 0, {0}};

    init_sprite(&new_block, path);
    data->block_list = push(data->block_list, new_block);
}

void search_block_for_make(data_st *data, sfVector2i pos)
{
    for (pos.x = 0; data->map.map[pos.y][pos.x] != '\0'; pos.x++) {
        switch (data->map.map[pos.y][pos.x]) {
            case '1':
                make_block(data, pos, NOTHING, "lib/images/stone_brick.png");
                break;
            case '2':
                make_block(data, pos, BOUNCE, "lib/images/slime_bounce.png");
                break;
            case '3':
                make_block(data, pos, KILL, "lib/images/trap.png");
                break;
            case '4':
                make_block(data, pos, PICKABLE_ITEM, \
                "lib/images/coin_sheet.png");
                break;
            case '5':
                make_block(data, pos, END, "lib/images/final.png");
        }
    }
}

void make_map(data_st *data)
{
    for (sfVector2i pos = {0, 0}; pos.y < data->map.y; pos.y++)
        search_block_for_make(data, pos);
}
