/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct map_s
{
    int rep;
    char *map;
    char **tab_map;
    int nb_space;
    int nb_pipe;
    int line_player;
    int matches_player;
} map_t;

char **my_str_to_word_array(char *str);
int my_getnbr(char *str);
void    my_putstr(char *str, int space, int slash);
char *cat(char *start, char *line);
void    my_put_nbr(int nb, int space, int slash);
int my_strlen(char *str);