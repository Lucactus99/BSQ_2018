/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int display_square(char **map_2d, int sizeBSQ, int xstart, int ystart, struct length *len)
{
    for (int i = 0; i < sizeBSQ; i++) {
        for (int j = 0; j < sizeBSQ; j++) {
            map_2d[ystart + i][xstart + j] = 'x';
        }
    }
    if (ystart == 0) {
        map_2d[ystart][xstart - 1] = 'x';
        map_2d[ystart][xstart + sizeBSQ - 1] = 'x';
    }
    for (int i = 0; i < len->lengthy; i++) {
        write(1, map_2d[i], len->lengthx + 1);
    }
    return (0);
}

int check_size_square_y(char **map_2d, int x, int y, int i, int sizeBSQ)
{
    for (int j = 0; j < sizeBSQ; j++) {
        if (map_2d[y + i][x + j] != '.') {
            return (1);
        }
    }
    return (0);
}

int check_size_square(char **map_2d, int sizeBSQ, int x, int y, struct length *len)
{
    int xstart = 0;
    int ystart = 0;

    for (int i = 0; i < sizeBSQ; i++) {
        if (check_size_square_y(map_2d, x, y, i, sizeBSQ) == 1)
            return (1);
    }
    xstart = x;
    ystart = y;
    return (display_square(map_2d, sizeBSQ, xstart, ystart, len));
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
    return (length);
}

int find_map_3(char **map_2d, int y, int m, int sizeBSQ, struct length *len)
{
    for (int x = 0; x < m - 1; x++) {
        if (check_size_square(map_2d, sizeBSQ, x, y, len) == 0) {
            return (0);
        }
    }
    return (1);
}

int find_map_2(char **map_2d, int m, int sizeBSQ, struct length *len, int l)
{
    for (int y = 0; y < l; y++) {
        if (find_map_3(map_2d, y, m, sizeBSQ, len) == 0)
            return (0);
    }
    return (1);
}

int find_map(char *map, char **map_2d, int l, int m, struct length *len)
{
    for (int sizeBSQ = find_max_length(map); sizeBSQ > 0; sizeBSQ--) {
        if (find_map_2(map_2d, m, sizeBSQ, len, l) == 0)
            return (0);
    }
    return (1);
}

int create_map(char *map, struct stat sb, struct length *len)
{
    char **map_2d = malloc(sizeof(char *) * sb.st_size + 3);
    int j = 0;
    int l = 0;
    int m = 0;

    for (int k = 0; map[k] != '\0'; k++) {
        map_2d[k] = malloc(sizeof(char) * len->lengthx + 1);
        map_2d[k][len->lengthx] = '\n';
    }
    for (int i = 0; i < sb.st_size + 2; i++) {
        if (j == len->lengthx + 1) {
            m = j;
            j = 0;
            l++;
        }
        map_2d[l][j] = map[i];
        j++;
    }
    return (find_map(map, map_2d, l, m, len));
}

int length_map_y(char **map)
{
    int length = 0;

    for (int i = 0; map[0][i] >= 48 && map[0][i] <= 57;) {
        length += map[0][i] - 48;
        length *= 10;
        map[0]++;
    }
    map[0]++;
    length /= 10;
    return (length);
}

int length_map_x(char *map)
{
    int length = 0;

    for (int i = 0; map[i] != '\n'; i++)
        length++;
    return (length);
}

int check_error(int argc, int fd, int size)
{
    if (argc != 2)
        return (84);
    if (fd == - 1) {
        my_putstr("Error with opn\n");
        return (84);
    }
    if (size == 0)
        return (84);
    return (0);
}

int main(int argc, char *argv[])
{
    struct stat sb;
    stat(argv[1], &sb);
    char *buff = malloc(sizeof(char) * sb.st_size + 2);
    int fd = open(argv[1], O_RDONLY);
    int size = read(fd, buff, sb.st_size);
    struct length *len;
    len = malloc(sizeof(struct length));
    len->lengthy = length_map_y(&buff);
    len->lengthx = length_map_x(buff);

    if (check_error(argc, fd, size) == 84)
        return (84);
    buff[my_strlen(buff)] = '\0';
    create_map(buff, sb, len);
    close(fd);
    return (0);
}
