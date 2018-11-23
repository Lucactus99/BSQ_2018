/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** bsq_main
*/

#include "my.h"

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
    if (size < 0)
        return (84);
    return (0);
}

int main(int argc, char *argv[])
{
    struct stat sb;
    stat(argv[1], &sb);
    char *buff = NULL;
    int fd = open(argv[1], O_RDONLY);
    int size = 0;
    struct length *len = malloc(sizeof(struct length));

    buff = malloc(sizeof(char) * (sb.st_size + 1));
    size = read(fd, buff, sb.st_size);
    if (check_error(argc, fd, size) == 84)
        return (84);
    buff[sb.st_size] = '\0';
    len->lengthy = length_map_y(&buff);
    len->lengthx = length_map_x(buff);
    create_map(buff, len);
    close(fd);
    free(len);
    return (0);
}
