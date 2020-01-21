##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	my_getnbr.c	\
		main.c	\
		my_str_to_word_array.c	\
		my_putstr.c	\
		cat.c	\
		my_put_nbr.c	\
		my_strlen.c	\

NAME	=	matchstick

OBJ	=	libmy.a

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

VG	=	-g3

ERROR	=	-Wall -W -Wextra

LIBRARY	=	-L. -lmy -I include

LIB	=	-L. -lmy -I include

all	:	$(OBJ)

$(OBJ)	:
	gcc -o $(NAME) $(SRC) $(VG)

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
