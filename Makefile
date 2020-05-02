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
		src/flag.c									\
		src/init_struct.c							\
		src/window.c								\
		src/loading.c 								\
		src/manage_view.c 							\
		src/object/create_object.c 					\
		src/object/set_position_object.c 			\
		src/object/anim_object.c 					\
		src/object/set_background_pos.c 			\
		src/object/player/check_move.c 				\
		src/object/player/move_player.c 			\
		src/object/player/create_player.c 			\
		src/object/player/anim_player.c 			\
		src/object/player/manage_player.c 			\
		src/menu/create_button.c					\
		src/menu/init_button.c 						\
		src/menu/manage_start_menu.c 				\
		src/menu/manage_menu_pause.c 				\
		src/rect/rect_arr.c							\
		src/rect/rect_shape.c 						\
		src/rect/free_rect_arr.c 					\
		src/rect/manage_rect.c 						\
		src/map/create_map.c 						\
		src/map/free_map.c 							\
		src/map/read_mapfile.c 						\
		src/map/set_map.c 							\
		src/map/manage_map.c 						\
		src/map/change_map.c 						\
		src/map/load_scene_up.c 					\
		src/map/load_scene_down.c 					\
		src/event/key_move.c 						\
		src/event/management.c 						\
		src/event/manage_key.c 						\
		src/event/color_cursor.c 					\
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
		src/fight/manage_fight.c 					\
		src/save/load_save.c 						\
		src/save/reset_file.c 						\
		src/save/manage_save.c 						\
		src/save/save_stat.c  						\
		src/display/display.c 						\
		src/display/display_map.c 					\
		src/display/display_menu_start.c 			\
		src/display/display_menu_pause.c 			\
		src/dialogue/init_dialogue.c				\
		src/dialogue/init_rectangle.c				\
		src/dialogue/how_to_play.c					\
		src/dialogue/manage_dialogue.c 				\
		src/inventory.c								\
		src/particule/rain.c						\
		src/game/manage_game.c 						\
		src/game/pnj.c 								\
		src/game/enemi.c 							\
		src/sounds/create_sounds.c					\
		src/free/destroy_all.c 						\
		src/free/destroy_button.c 					\
		src/free/destroy_clock.c 					\
		src/free/destroy_music.c 					\
		src/free/destroy_object.c 					\
		src/free/destroy_textures.c 				\

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

reset: all
	@$(RM) .config/maps/* .config/save
	@./$(NAME) --reset

.PHONY: all debug clean fclean re tests_run reset

tests_run:	LDFLAGS	+= -lcriterion --coverage
tests_run:
		gcc -o unit_tests  $(CPPFLAGS) $(LDFLAGS)
		./unit_tests
		gcovr -e tests/
