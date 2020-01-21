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

void    print_table(int nb_line, map_t *map_game)
{
    for (int z = 0; z < nb_line + 2; z += 1) {
        write(1, map_game->tab_map[z], ((nb_line * 2) + 2));
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

void print_updated_board_game(int line , int nb_matches, map_t *map_game,\
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

int line_calc(int a, map_t *map_game, int line)
{
    char buffer[32000];
    
    for (; a == 0;) {
    write (0, "Line: ", 6);
    read (0, buffer, 137);
    map_game->line_player = my_getnbr(buffer);
        a = 1;
        if (map_game->line_player <= 0 || map_game->line_player > line) {
            write(0, "youston on a un pb avec la line\n", 32);
            a = 0;
        }
    }
    return a;
}

int matches_calc(int b, map_t *map_game, int matches)
{
    char buffer[32000];

    write (0, "Matches: ", 9);
    read (0, buffer, 137);
    map_game->matches_player = my_getnbr(buffer);
    b = 1;
    if (map_game->matches_player <= 0 || map_game->matches_player > check_pipe\
    (map_game->tab_map, map_game->line_player) || map_game->matches_player \
    > matches) {
        write(0, "youston on a un pb avec le nbr de matches\n", 48);
        b = 0;
    }
    return (b);
}

void player(map_t *map_game, char **av)
{
    int line = my_getnbr(av[1]);
    int matches = my_getnbr(av[2]);
    int a;
    int b = 0;

    map_game->line_player = 0;
    map_game->matches_player = 0;
    for (; b == 0;) {
        a = 0;
        a = line_calc(a, map_game, line);
        b = matches_calc(b, map_game, matches);
    }
    print_updated_board_game(map_game->line_player, map_game->\
    matches_player, map_game, line);
}

int loop_game(map_t *map_game, char **av)
{
    for (;end(map_game->tab_map) == 0 ;) {
        player(map_game, av);
        if (end(map_game->tab_map) == 1)
            return (1);
        // ia()
        // if (end(map_game) == 1)
        //     return (2);
    }
}

int main(int ac, char **av)
{
    map_t *map_game = malloc(sizeof(map_t));

    if (ac != 3)
        return (84);
    create_map(my_getnbr(av[1]), map_game);
    map_game->tab_map = my_str_to_word_array(map_game->map);
    print_table(my_getnbr(av[1]), map_game);
    return(loop_game(map_game, av));
}