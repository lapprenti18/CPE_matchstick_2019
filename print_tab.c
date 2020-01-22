/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
**  fs_understand_return_of_ read.c
*/

#include "my.h"

void    print_table(int nb_line, map_t *map_game)
{
    for (int z = 0; z < nb_line + 2; z += 1) {
        write(1, map_game->tab_map[z], ((nb_line * 2) + 1));
        write(1, "\n", 1);
    }
}

void first_line(map_t *map_game, int line)
{
    for (; map_game->rep < ((line - 1) * 2 + 3) ; map_game->rep += 1)
        map_game->map[map_game->rep] = '*';
    map_game->map[map_game->rep] = '\n';
    map_game->rep += 1;
}

void dead_line(map_t *map_game, int line)
{
    for (int z = 0; z < ((line - 1) * 2 + 3) ; z += 1) {
        map_game->map[map_game->rep] = '*';
        map_game->rep += 1;
    }
}

void space(map_t *map_game, int line)
{
    for (int z = 0; z < map_game->nb_space/ 2; z += 1) {
        map_game->map[map_game->rep] = ' ';
        map_game->rep += 1;
    }
}

void pippe(map_t *map_game, int line)
{
    for (int z = 0; z < map_game->nb_pipe; z += 1) {
        map_game->map[map_game->rep] = '|';
        map_game->rep += 1;
    }
}