/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

char **display_square(char **map_2d, int sizeBSQ, int xstart, int ystart)
{
    for (int i = 0; i < sizeBSQ; i++) {
        for (int j = 0; j < sizeBSQ; j++) {
            map_2d[ystart + i][xstart + j] = 'x';
        }
    }
    if (ystart == 0) {
        map_2d[ystart][xstart - 1] = 'x';
        map_2d[ystart][xstart + sizeBSQ - 1] = '.';
    }
    return (map_2d);
}

char **check_size_square(char **map_2d, int sizeBSQ, int x, int y)
{
    int xstart = 0;
    int ystart = 0;

    for (int i = 0; i < sizeBSQ; i++) {
        for (int j = 0; j < sizeBSQ; j++) {
            if (map_2d[y + i][x + j] != '.') {
                return (map_2d);
            }
        }
    }
    xstart = x;
    ystart = y;
    return (display_square(map_2d, sizeBSQ, xstart, ystart));
}

char **print_array_first_line(char *map, struct stat sb, int lengthx, int lengthy)
{
    char **map_2d = malloc(sizeof(char *) * sb.st_size + 3);
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int sizeBSQ = 0;

    for (k = 0; map[k] != '\0'; k++) {
        map_2d[k] = malloc(sizeof(char) * lengthx + 1);
    }
    for (i = 0; i < sb.st_size + 2; i++) {
        if (j == lengthx + 1) {
            m = j;
            j = 0;
            l++;
        }
        map_2d[l][j] = map[i];
        j++;
    }
    for (sizeBSQ = 20; sizeBSQ > 0; sizeBSQ--) {
        for (int y = 0; y < l; y++) {
            for (int x = 0; x < m - 1; x++) {
                map_2d = check_size_square(map_2d, sizeBSQ, x, y);
                if (map_2d[y][x] == 'x') {
                    return (map_2d);
                }
            }
        }
    }
    return (map_2d);
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

int main(int argc, char *argv[])
{
    int fd;
    char **map_2d;
    struct stat sb;
    stat(argv[1], &sb);
    int size = 0;
    int lengthy;
    int lengthx;
    char *buff = malloc(sizeof(char) * sb.st_size + 2);

    if (argc != 2)
        return (84);
    fd = open(argv[1], O_RDONLY);
    if (fd == - 1) {
        my_putstr("Error with opn\n");
        return (84);
    }
    size = read(fd, buff, sb.st_size);
    lengthy = length_map_y(&buff);
    lengthx = length_map_x(buff);
    map_2d = print_array_first_line(buff, sb, lengthx, lengthy);
    for (int i = 0; i < lengthy; i++)
        write(1, map_2d[i], lengthx + 1);
    close(fd);
    return 0;
}
