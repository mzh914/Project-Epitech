##
## EPITECH PROJECT, 2020
## makefile
## File description:
## bistro makefile
##

RM	=	-rm -rf

# Source files
## Lib
LIB_SRC	= \
	my_itoa.c	\
	my_revstr.c	\
	my_strlen.c	\
	my_getnbr.c	\
	binary.c	\
	hexa_base_maj.c	\
	hexa_base.c	\
	my_printf.c	\
	my_put_nbr.c	\
	my_putchar.c	\
	my_putnbr_base.c	\
	my_putstr.c	\
	octal_base.c	\
	switch.c	\
	my_strcmp.c	\

## Project
SRC = \
	place_boats.c	\
	file.c	\
	connect_term.c	\
	signal.c	\
	error_boats.c	\
	gameloop.c	\
	end_game.c	\
	place_boats_norm.c	\
	signal_norm.c	\

## Main
MAIN_SRC    =   main.c

## Unit Tests
UNIT_TEST_SRC  =   \
	unit_tests.c   \

## Sources required by any rule
COMMON_SRC	=							\
	$(addprefix src/, $(SRC))			\
	$(addprefix lib/my/, $(LIB_SRC))

## Sources for the binary
BIN_SRC	=			\
	$(COMMON_SRC)	\
	$(MAIN_SRC)	\

## Sources for the unit tests
UT_SRC	=									\
	$(addprefix	tests/, $(UNIT_TEST_SRC))	\
	$(COMMON_SRC)

## Object files for binary
BIN_OBJ	=	$(BIN_SRC:.c=.o)

# Compilation flag
CPPFLAGS	=	-Iinclude
CFLAGS		=	-Wall -Wextra

# Binaries' names
NAME	=	navy
TEST	=	unit_tests

# Compilation Rules
## Binary
all:    $(NAME)
$(NAME):    $(BIN_OBJ)
			gcc $(BIN_OBJ) -o $(NAME) $(CPPFLAGS) $(CFLAGS)

## Unit tests
tests_run: LDFLAGS	+= -lcriterion
tests_run: CFLAGS	+= --coverage
tests_run:
	gcc $(UT_SRC) -o $(TEST) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)
	./$(TEST)
	-@mkdir .tmp &> /dev/null
	-@mv test_*.gc* .tmp
	gcovr -r . --exclude-directories .tmp
	gcovr -r . -b --exclude-directories .tmp

## Debug
debug:	CFLAGS	+= -g3
debug:	all

## Rebuild all
re: fclean all
redbg: fclean debug

# Clean Rules
clean:
	$(RM) $(BIN_OBJ)
	$(RM) *.gc*
	$(RM) .tmp

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST)

# Misc
.PHONY: $(NAME) tests_run debug re redbg clean fclean