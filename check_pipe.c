/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
**  fs_understand_return_of_ read.c
*/

#include "my.h"

int check_pipe(char **tab_map, int line)
{
    int pipe = 0;

    for (int a = 0; tab_map[line][a]; a += 1)
        if (tab_map[line][a] == '|')
            pipe += 1;
    return (pipe);
}