##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/reallocation.c 			\
		src/my_strcmp.c 			\
		src/setenv.c 				\
		src/my_str_to_word_array.c 	\
		src/my_strcat.c 			\
		src/env_copy.c 				\
		src/unsetenv.c 				\
		src/cd_function.c 			\
		src/pwd_gestion.c 			\
		src/exec_gestion.c 			\
		src/exec_function.c 		\
		src/env_function.c 			\
		src/free_function.c 		\
		src/parser.c 				\
		src/parse_str.c 			\
		src/check_ambigous.c 		\
		src/symbole.c 				\
		src/error_gestion.c 		\
		src/tree.c 					\
		src/exec_redirection.c 		\
		src/not_disp/cd_not_disp.c 	\
		src/not_disp/compare.c 		\
		src/not_disp/setenv_not_disp.c 	\
		src/not_disp/unsetenv_not_disp.c 	\
		src/compare.c 						\
		src/error_str.c 					\

SRC_TEST 	= tests/unit_tests.c     \


OBJ	=	$(SRC:.c=.o)

OBJ_TEST	= 	$(SRC_TEST:.c=.o)

NAME	=	mysh

NAME_T  =       unit_tests

CC	=	gcc -g3

CFLAGS  =       -I./include/ -L./lib/ -lmy -Wall -Wextra

FLAG_T  =       --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/
		$(CC) -o $(NAME) $(OBJ) src/main.c $(CFLAGS)

tests_run: $(OBJ_TEST)
			make re
			gcc -o $(NAME_T) $(SRC) $(SRC_TEST) $(CFLAGS) $(FLAG_T)
			./$(NAME_T)

clean:
		rm -f src/*.o
		rm -f tests/*.o
		rm -f src/not_disp/*.o
		make clean -C lib/

fclean:		clean
		rm -f $(NAME)
		make fclean -C lib/

tclean:		fclean
		rm -f $(NAME_T)
		rm -f *gcno
		rm -f *gcda

re:		fclean all
		make re -C lib/

