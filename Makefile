##
## EPITECH PROJECT, 2019
## CPE_pushswap_2019
## File description:
## Makefile
##

######### FLAGS #########
CFLAGS	=	-Wall -Wextra -Wshadow -finline-functions

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS = -L lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

######### SOURCES #########
SRC =	src/main.c									\
		src/init_struct.c							\
		src/window.c								\
		src/loading.c 								\
		src/display.c 								\
		src/object/create_object.c 					\
		src/object/set_position_object.c 			\
		src/object/player/check_move.c 				\
		src/object/player/move_player.c 			\
		src/object/player/create_player.c 			\
		src/object/player/anim_player.c 			\
		src/object/player/manage_player.c 			\
		src/object/anim_object.c 					\
		src/create_button.c							\
		src/create_menu.c							\
		src/rect/rect_arr.c							\
		src/rect/rect_shape.c 						\
		src/rect/free_rect_arr.c 					\
		src/rect/manage_rect.c 						\
		src/map/create_map.c 						\
		src/map/free_map.c 							\
		src/map/read_mapfile.c 						\
		src/map/set_map.c 							\
		src/event/key_move.c 						\
		src/event/management.c 						\
		src/event/manage_key.c 						\
		src/save/save_game.c 						\
		src/particule/particule.c					\
		src/particule/particule_update.c			\
		src/particule/free_particule.c				\
		src/fight/position.c						\
		src/fight/init_fight.c						\
		src/fight/key_press.c						\
		src/fight/battle.c							\
		src/fight/god_mode.c						\
		src/fight/status_battle.c					\
		src/fight/set_sprite.c						\
		src/fight/main_fight.c						\
		src/save/load_save.c 						\
		src/save/manage_save.c 						\
		src/save/save_stat.c  						\

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
