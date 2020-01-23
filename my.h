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
    int max_matches;
    char *line_remove;
    char *matches_remove;
} map_t;

char **my_str_to_word_array(char *str);
int my_getnbr(char *str);
void    my_putstr(char *str, int space, int slash);
char *cat(char *start, char *line);
void    my_put_nbr(int nb, int space, int slash);
int my_strlen(char *str);
int check_pipe(char **tab_map, int line);
void    print_table(int nb_line, map_t *map_game);
void first_line(map_t *map_game, int line);
void dead_line(map_t *map_game, int line);
void space(map_t *map_game, int line);
void pippe(map_t *map_game, int line);
void calc_line(map_t *map_game);
void create_map(int line, map_t *map_game);
void print_updated_board_game(int line , int nb_matches, map_t *map_game, \
int line_tot);
int end(char **map_game);
void error_line(map_t *map_game, int line, char *enter);
int line_calc(int a, map_t *map_game, int line);
void error_matches(map_t *map_game, int matches);
int matches_calc(int b, map_t *map_game, int matches);
void delete_slash(map_t *map_game);