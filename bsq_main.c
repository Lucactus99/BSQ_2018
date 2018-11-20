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
    struct length *len = malloc(sizeof(struct length));
    len->lengthy = length_map_y(&buff);
    len->lengthx = length_map_x(buff);

    if (check_error(argc, fd, size) == 84)
        return (84);
    buff[my_strlen(buff)] = '\0';
    create_map(buff, sb, len);
    close(fd);
    return (0);
}
