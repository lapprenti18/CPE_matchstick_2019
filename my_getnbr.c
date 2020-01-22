/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
int i = 0;
int neg = 1;
int n;

    for (int temp = 0; str[temp]; temp += 1) {
        if (str[temp] < '0' && str[temp] != '\n' \
        || str[temp] > '9' && str[temp] != '\n')
            return (-1);
    }
    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
            neg = neg * -1;
    i++;
    }
    n = 0;
    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + str[i] - 48;
        i++;
    }
    return (n * neg);
}