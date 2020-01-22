/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
**  fs_understand_return_of_ read.c
*/

#include "my.h"

int end(char **map_game)
{
    int pipe = 0;

    for (int a = 0; map_game[a]; a += 1) {
        for (int b = 0; map_game[a][b]; b += 1) {
            if (map_game[a][b] == '|')
                pipe += 1;
        }
    }
    if (pipe == 0)
        return (1);
    return (0);
}

void print_updated_board_game(int line , int nb_matches, map_t *map_game, \
int line_tot)
{
    int a = 0;

    for (; map_game->tab_map[line][a + 1]; a += 1);
    for (; nb_matches != 0; a -= 1) {
        if (map_game->tab_map[line][a] == '|') {
            nb_matches -= 1;
            map_game->tab_map[line][a] = ' ';
        }
    }
    print_table(line_tot, map_game);
}