/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
**  fs_understand_return_of_ read.c
*/

#include "my.h"

void display_player(map_t *map_game)
{
    delete_slash(map_game);
    my_putstr("Player removed", 1, 0);
    my_putstr(map_game->matches_remove, 1, 0);
    my_putstr("match(es) from line", 1, 0);
    my_putstr(map_game->line_remove, 0, 1);
}

int player(map_t *map_game, char **av)
{
    int line = my_getnbr(av[1]);
    int matches = my_getnbr(av[2]);
    int a;
    int b = 0;

    write(1, "\nYour turn:\n", 12);
    map_game->line_player = 0;
    map_game->matches_player = 0;
    for (; b == 0;) {
        a = 0;
        if ((a = line_calc(a, map_game, line)) == -1)
            return (-1);
        write(1, "Matches: ", 9);
        b = matches_calc(b, map_game, matches);
    }
    if (a == -1 || b == -1)
        return (-1);
    display_player(map_game);
    print_updated_board_game(map_game->line_player, map_game->\
    matches_player, map_game, line);
    return (0);
}

void ia(map_t *map_game, char **av)
{
    int temp = 0;
    int pipe = 0;
    int line = my_getnbr(av[1]);

    for (; map_game->tab_map; temp += 1) {
        if ((check_pipe(map_game->tab_map, temp)) != 0)
            break;
    }
    pipe = (((my_getnbr(av[1]) - 1) * 2) + 3);
    for (; map_game->tab_map[temp][pipe] != '|'; pipe -= 1);
    map_game->tab_map[temp][pipe] = ' ';
    my_putstr("\nAI's turn...\nAI removed 1 match(es) from line", 1, 0);
    my_put_nbr(temp, 0, 1);
    print_table(line, map_game);
}

int loop_game(map_t *map_game, char **av)
{
    for (;end(map_game->tab_map) == 0 ;) {
        if (player(map_game, av) == -1)
            return (0);
        if (end(map_game->tab_map) == 1) {
            my_putstr("You lost, too bad...", 0, 1);
            return (1);
        }
        ia(map_game, av);
        if (end(map_game->tab_map) == 1) {
            write(1, "I lost... snif... but I'll get you next time!!\n", 47);
            return (2);
        }
    }
}

int main(int ac, char **av)
{
    map_t *map_game = malloc(sizeof(map_t));

    if (ac != 3)
        return (84);
    if (my_getnbr(av[1]) <= 0 || my_getnbr(av[2]) <= 0)
        return (84);
    create_map(my_getnbr(av[1]), map_game);
    map_game->tab_map = my_str_to_word_array(map_game->map);
    print_table(my_getnbr(av[1]), map_game);
    map_game->max_matches = my_getnbr(av[2]);
    return (loop_game(map_game, av));
}