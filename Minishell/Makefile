##
## EPITECH PROJECT, 2020
## pushswap
## File description:
## Makefile
##

LIB_SRC = \
	my_putstr.c	\
	my_getstr.c	\
	my_strlen.c	\
	my_strcat.c	\
	my_strcpy.c	\
	my_printf.c	\
	my_revstr.c	\
	flag_char.c	\
	my_getnbr.c	\
	my_strcmp.c	\
	my_putchar.c	\
	my_strncmp.c	\
	my_strncpy.c	\
	my_put_nbr.c	\
	basic_case.c	\
	fct_for_flag.c	\
	my_convert_base.c	\

SRC = \
	env.c	\
	exec.c	\
	myshell.c	\
	utility.c	\
	change_dir.c	\
	line_formating.c	\

UT_SRC = \

MAIN_SRC = main.c

COMMON_SRC =	\
	$(addprefix src/, $(SRC))	\
	$(addprefix lib/, $(LIB_SRC))	\

BIN_SRC	=	\
	$(COMMON_SRC)	\
	$(MAIN_SRC)

UT_OBJ	=	\
	$(addprefix tests/, $(UT_SRC))	\
	$(COMMON_SRC)

BIN_OBJ	=	$(BIN_SRC:.c=.o)

CPPFLAGS	=	-Iinclude -Ilib/include
CFLAGS	=	-Wall -Wextra

NAME	=	mysh
TEST	=	unit_tests

all:	$(NAME)
$(NAME):	$(BIN_OBJ)
			gcc $(BIN_OBJ) -o $(NAME) $(CPPFLAGS) $(CFLAGS)

tests_run:	LDFLAGS	+= -lcriterion
tests_run:	CFLAGS	+=	--coverage
tests_run:
	gcc	$(UT_OBJ) -o $(TEST) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)
	./$(TEST)
	-@mkdir .tmp &> /dev/null
	-@mv test_*.gc* .tmp
	gcovr -r . --exclude-directories .tmp
	gcovr -r . -b --exclude-directories .tmp

debug:	CFLAGS	+= -g3
debug:	all

re: fclean all
redbg: fclean debug

clean:
	$(RM) $(BIN_OBJ)
	$(RM) *.gc*
	$(RM) .tmp

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST)

.PHONY: $(NAME) tests_run debug re redbg clean fclean