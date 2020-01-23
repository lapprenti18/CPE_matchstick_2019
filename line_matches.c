/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
**  fs_understand_return_of_ read.c
*/

#include "my.h"

void error_line(map_t *map_game, int line, char *enter)
{
    if (map_game->line_player > line || map_game->line_player == 0)
        my_putstr("Error: this line is out of range", 0, 1);
    if (my_getnbr(enter) < 0)
        my_putstr("Error: invalid input (positive number expected)", 0, 1);
}

int line_calc(int a, map_t *map_game, int line)
{
    size_t len = 0;
    ssize_t read;
    char *enter = NULL;

    for (; a == 0;) {
    write (1, "Line: ", 6);
    if ((read = getline(&enter, &len, stdin)) == -1)
        return (-1);
    map_game->line_player = my_getnbr(enter);
        a = 1;
        if (map_game->line_player <= 0 || map_game->line_player > line) {
            error_line(map_game, line, enter);
            a = 0;
        }
    }
    return a;
}

void error_matches(map_t *map_game, int matches)
{
    if (map_game->matches_player > check_pipe\
    (map_game->tab_map, map_game->line_player))
        my_putstr("Error: not enough matches on this line", 1, 1);
    if (map_game->matches_player > map_game->max_matches && map_game->\
    matches_player <= check_pipe(map_game->tab_map, map_game->line_player)) {
        my_putstr("Error: you cannot remove more than", 1, 0);
        my_put_nbr(map_game->max_matches, 1, 0);
        my_putstr("matches per turn", 0, 1);
    }
    if (map_game->matches_player == 0)
        my_putstr("Error: you have to remove at least one match", 0, 1);
    if (map_game->matches_player == -1)
        my_putstr("Error: invalid input (positive number expected)", 0, 1);
}

int matches_calc(int b, map_t *map_game, int matches)
{
    size_t len = 0;
    ssize_t read;
    char *enter = NULL;

    if ((read = getline(&enter, &len, stdin)) == -1)
        return (-1);
    map_game->matches_player = my_getnbr(enter);
    b = 1;
    if (map_game->matches_player <= 0 || map_game->matches_player > check_pipe\
    (map_game->tab_map, map_game->line_player) || map_game->matches_player \
    > matches) {
        error_matches(map_game, matches);
        b = 0;
    }
    return (b);
}