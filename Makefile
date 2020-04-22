##
## EPITECH PROJECT, 2019
## CPE_pushswap_2019
## File description:
## Makefile
##

######### FLAGS #########
CFLAGS	=	-Wall -Wextra  -Wshadow -finline-functions

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS = -L lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

######### SOURCES #########
SRC =	src/main.c				\
		src/init_struct.c		\
		src/window.c			\
		src/loading.c 			\
		src/create_object.c 	\
		src/fight/position.c	\
		src/fight/init_fight.c	\
		src/fight/key_press.c	\
		src/fight/battle.c	\

OBJ = $(SRC:.c=.o)

NAME =	my_rpg

IDIR	=	./include

CC	=	gcc

######### Rules ###########
all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

debug: CFLAGS += $(DBGFLAGS)
debug: re

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)

re:	fclean all

.PHONY: all debug clean fclean re tests_run

tests_run:	LDFLAGS	+= -lcriterion --coverage
tests_run:
		gcc -o unit_tests  $(CPPFLAGS) $(LDFLAGS)
		./unit_tests
		gcovr -e tests/
