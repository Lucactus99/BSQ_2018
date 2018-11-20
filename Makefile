##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC      =       gcc

SRC     =	bsq_main.c \
		bsq_check_size.c \
		bsq_find_map.c \
		src/my_putchar.c \
		src/my_putstr.c \
		src/my_strlen.c

OBJ     =       $(SRC:.c=.o)

NAME    =       bsq

CFLAGS  =       -W -Wall -ansi -pedantic -g -std=c99 -I include

all:    $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
