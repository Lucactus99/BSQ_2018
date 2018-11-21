/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** bsq_find_map
*/

#include "my.h"

int find_map_3(char **map_2d, int sizeBsq, struct length *len)
{
    for (len->x = 0; len->x < len->lengthx; len->x++) {
        if (check_size_square(map_2d, sizeBsq, len) == 0) {
            return (0);
        }
    }
    return (1);
}

int find_map_2(char **map_2d, int sizeBsq, struct length *len)
{
    for (len->y = 0; len->y < len->lengthy; len->y++) {
        if (find_map_3(map_2d, sizeBsq, len) == 0)
            return (0);
    }
    return (1);
}

int find_map(char *map, char **map_2d, struct length *len)
{
    for (int sizeBsq = find_max_length(map); sizeBsq > 0; sizeBsq--) {
        if (find_map_2(map_2d, sizeBsq, len) == 0)
            return (0);
    }
    return (1);
}

void create_map(char *map, struct length *len)
{
    char **map_2d = malloc(sizeof(char *) * (len->lengthy + 1));
    int j = 0;
    int l = 0;

    for (int k = 0; k < len->lengthy + 1; k++) {
        map_2d[k] = malloc(sizeof(char) * (len->lengthx + 1));
    }
    for (int i = 0; map[i] != '\0'; i++) {
        if (j == len->lengthx + 1) {
            j = 0;
            l++;
        }
        map_2d[l][j] = map[i];
        j++;
    }
    if (find_map(map, map_2d, len) == 1)
        my_putstr(map);
    free(map_2d);
}

int display_square(char **map_2d, int sizeBsq,
struct position *pos, struct length *len)
{
    for (int i = 0; i < sizeBsq; i++) {
        for (int j = 0; j < sizeBsq; j++) {
            map_2d[pos->ystart + i][pos->xstart + j] = 'x';
        }
    }
    for (int i = 0; i < len->lengthy; i++) {
        write(1, map_2d[i], len->lengthx);
        my_putchar('\n');
    }
    return (0);
}