/*
** EPITECH PROJECT, 2018
** My_Hunter
** File description:
** My_Hunter
*/

#include "include/my_runner.h"

int check_error(int ac, char **av)
{
    if (ac == 1) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        return (84);
    } else if (av[1][0] == '-' && av[1][1] == 'h' && ac == 2) {
        my_putstr("Finite runner created with CSFML.\n\nUSAGE\n ");
        my_putstr("./my_runner [file_name]\n\n\nOPTIONS\n -h     ");
        my_putstr("print the usage and quit.");
        my_putstr("\n\nUSER INTERACTIONS\n SPACE_KEY        jump.\n");
        my_putstr(" ESCAPE:          pause menu.\n");
        return (84);
    }
    if (ac != 2) {
        my_putstr("./my_runner: bad arguments: 1 is required (map file)\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    sfVideoMode v_mode = {1536, 864, 32};
    data_st data;
    data_menu_st data_menu;
    int continu = 1;

    if (check_error(ac, av) == 84)
        return (84);
    window = sfRenderWindow_create(v_mode, "My_Runner", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    launch_runner(&continu, &data, &data_menu, window);
    free(data_menu.menu_level.path_level);
    destroy_all(window, &data, &data_menu);
    return (0);
}
