/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** bsq_check_size
*/

#include "my.h"

int check_size_square_y(char **map_2d, struct length *len, int i, int sizeBSQ)
{
    for (int j = 0; j < sizeBSQ; j++) {
        if (map_2d[len->y + i][len->x + j] != '.') {
            return (1);
        }
    }
    return (0);
}

int check_size_square(char **map_2d, int sizeBSQ, struct length *len)
{
    struct position pos;
    pos.xstart = 0;
    pos.ystart = 0;

    for (int i = 0; i < sizeBSQ; i++) {
        if (check_size_square_y(map_2d, len, i, sizeBSQ) == 1)
            return (1);
    }
    pos.xstart = len->x;
    pos.ystart = len->y;
    return (display_square(map_2d, sizeBSQ, &pos, len));
}

int find_max_length(char *map)
{
    int length = 0;
    int tmp = 0;

    for (int i = 0; map[i] != '\n'; i++) {
        for (int j = i; map[j] == '.'; j++) {
            tmp++;
            i = j;
        }
        if (tmp > length)
            length = tmp;
        tmp = 0;
    }
    if (length == 0)
        length = 1;
    return (length);
}

int check_map(char *map, struct length *len)
{
    int line = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '.' && map[i] != 'o' && map[i] != '\n') {
            return (84);
        }
        if ((map[i] == '\n') && (++i % (len->lengthy + 1) * ++line != 0))
            return (84);
    }
    if (line != len->lengthy)
        return (84);
    return (0);
}