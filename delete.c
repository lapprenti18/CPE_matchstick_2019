/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
**  fs_understand_return_of_ read.c
*/

#include "my.h"

void delete_slash(map_t *map_game)
{
    for (int a = 0; map_game->matches_remove[a]; a += 1) {
        if (map_game->matches_remove[a] == '\n')
            map_game->matches_remove[a] = '\0';
    }
    for (int a = 0; map_game->line_remove[a]; a += 1) {
        if (map_game->line_remove[a] == '\n')
            map_game->line_remove[a] = '\0';
    }
}