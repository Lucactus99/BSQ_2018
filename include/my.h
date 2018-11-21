/*
** EPITECH PROJECT, 2018
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

struct length {
    int lengthy;
    int lengthx;
    int x;
    int y;
};
struct position {
    int xstart;
    int ystart;
};

void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);
void create_map(char *, struct length *);
int display_square(char **, int, struct position *, struct length *);
int check_size_square(char **, int, struct length *);
int find_max_length(char *);
int check_map(char *, struct length *);

#endif //MY_H_
