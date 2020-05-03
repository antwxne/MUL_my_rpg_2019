##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile lib
##

#flags#

CFLAGS = -Wall -Wextra -Werror -Wshadow

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS =

#sources#

SRC = list_c.c	\
		convert_in_bit.c	\
		my_params_to_list.c	\
		my_strcat_int.c	\
		revstrint.c	\
		func_lib/function.c	\
		func_lib/my_getnbr.c	\
		func_lib/my_putnbr.c	\
		func_lib/my_realloc.c	\
		func_lib/my_str_isnum.c	\
		func_lib/my_strcat.c	\
		func_lib/my_strcmp.c	\
		func_lib/my_strcpy.c	\
		func_lib/my_strdup.c	\
		func_lib/my_strlen.c	\
		my_split.c 				\
		my_strlenc.c 			\
		free_char_arr.c 		\
		my_itoa.c 				\

OBJ = $(SRC:.c=.o)

NAME = libmy.a

LIB = libmy.a

IDIR = .

CC = gcc

#rules#

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc $(LIB) $(OBJ)
	mv $(LIB) ../
	cp my.h ../../include/

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(LIB)

re: fclean all

.PHONY: fclean clean re all debug
