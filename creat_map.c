/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
**  fs_understand_return_of_ read.c
*/

#include "my.h"

void calc_line(map_t *map_game)
{
    map_game->map[map_game->rep] = '*';
    map_game->rep += 1;
    map_game->map[map_game->rep] = '\n';
    map_game->rep += 1;
    map_game->nb_pipe += 2;
    map_game->nb_space -= 2;
}

void create_map(int line, map_t *map_game)
{
    int calc = ((line * 2) + 2) * (line + 2);
    map_game->map = malloc(sizeof(char) * calc);
    map_game->rep = 0;
    map_game->nb_space = (line - 1) * 2 + 1;
    map_game->nb_pipe = 1;

    map_game->map[calc - 1] = '\0';
    first_line(map_game, line);
    for (int nb_line = 1; nb_line < line + 1; nb_line += 1) {
        map_game->map[map_game->rep] = '*';
        map_game->rep += 1;
        space(map_game, line);
        pippe(map_game, line);
        space(map_game, line);
        calc_line(map_game);
    }
    dead_line(map_game, line);
}
