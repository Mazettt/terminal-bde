##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME	=	bde

# src
SRC_DIR	=	src/
EXTENSION	=	.c

SRC_FILES	=	graphics/events/events	\
				graphics/init/init_all	\
				graphics/init/init_screens	\
				graphics/init/init_spritesheets	\
				graphics/interface/buttons	\
				graphics/interface/check_click_buttons	\
				graphics/interface/check_mouse_on_buttons	\
				graphics/spritesheets/utils_sprites	\
				graphics/big_loop	\
				graphics/clean_window	\
				graphics/destroy_all	\
				graphics/draw_all	\
				graphics/utils	\
				get_datas	\
				get_id_card	\
				get_password	\
				main	\
				modify_database	\
				print_database	\

SRC	=	$(addprefix $(SRC_DIR), $(addsuffix $(EXTENSION), $(SRC_FILES)))

# no main
SRC_FILES_NO_MAIN	=	$(filter-out main, $(SRC_FILES))

SRC_NO_MAIN	=	$(addprefix $(SRC_DIR), $(addsuffix $(EXTENSION), $(SRC_FILES_NO_MAIN)))

# tests
TESTS_DIR	=	tests/

TESTS_FILES	=	tests.c	\

TESTS	=	$(addprefix $(TESTS_DIR), $(TESTS_FILES))

NAME_TESTS	=	unit_tests

# compil
OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

# clean
BIN	=	vgcore*	\
		unit_tests*	\

# flags
FLAGS	=	-I./include	\
		-g	\

WFLAGS	=	-Wall	\
			-Werror	\
			-Wextra	\

CSFML_FLAGS	=	-lcsfml-graphics	\
			-lcsfml-window	\
			-lcsfml-system	\
			-lcsfml-audio	\
			-lm

TESTS_FLAGS	=	--coverage	\
				-lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[1;34m\n============== Files compilation ok =============="
	@echo -e "\033[0m"
	$(CC) `mysql_config --cflags --libs` -o $(NAME) $(OBJ) $(FLAGS) $(CSFML_FLAGS) -lnfc
	@echo -e "\033[1;32m\n================= Compilation done ================="
	@echo -e "\033[0m"

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	@echo -e "\033[1;33m\n=============== Cleaning done ==============="
	@echo -e "\033[0m"

fclean:	clean
	rm -f $(NAME)
	@echo -e "\033[1;33m\n=============== Full cleaning done ==============="
	@echo -e "\033[0m"

re:	fclean all

exec:	re
	@echo
	@echo "-------------------------------------------------"
	@echo
	@./$(NAME)

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
		gcc -o $(NAME_TESTS) $(SRC_NO_MAIN) $(TESTS) $(TESTS_FLAGS) $(FLAGS)
		./$(NAME_TESTS)

.PHONY:		all clean fclean re exec gcovr tests_run
