##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

INIT	=		./lib/init/init_map.c		\
				./lib/init/init_window.c	\
				./lib/init/init_square.c	\
				./lib/init/update.c			\
				./lib/init/event.c			\
				./lib/init/init_button.c	\
				./lib/init/init_state.c		\
				./lib/init/init_suite.c		\
				./lib/init/check_over.c		\
				./lib/init/check_button.c	\
				./lib/init/destroy_suite.c	\
				./lib/init/button_suite.c	\
				./lib/init/check_resize.c	\
				./lib/init/my_atof.c		\
				./lib/init/my_ftostr.c		\
				./lib/init/save.c			\
				./lib/init/save_suite.c		\
				./lib/init/displayer.c		\
				./lib/init/load.c			\
				./lib/init/load_suite.c		\
				./lib/init/perlin.c			\
				./lib/init/perlin2.c		\
				./lib/init/load_color.c

LIST	=		./lib/linked_list_library/basing_functions.c	\
				./lib/linked_list_library/list_state.c	\
				./lib/linked_list_library/my_revstr.c	\
				./lib/linked_list_library/my_strcat.c	\
				./lib/linked_list_library/my_strlen.c

SCENE	=		./lib/sett_scene/init_button_scene.c	\
				./lib/sett_scene/launch_scene_settings.c	\
				./lib/sett_scene/click_scene.c

LOADNSAVE	=	./lib/loadnsave/asking_file.c

SRC		=		$(INIT)	\
				$(SCENE)	\
				$(LOADNSAVE)	\
				$(LIST)

OBJ		=		$(SRC:.c=.o)


MAIN 	=		main.c

SFML_FLAG	=		-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

C_FLAG	=		-lm

CC 		=		gcc -g3

NAME	=		my_world

all:		$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(MAIN) $(SFML_FLAG) $(C_FLAG)
		make clean
clean:
		rm -rf ./lib/init/*.o
		rm -rf ./lib/linked_list_library/*.o
		rm -rf ./lib/sett_scene/*.o
		rm -rf ./lib/loadnsave/*.o


fclean: clean
		rm -f $(NAME)

re:	fclean all
