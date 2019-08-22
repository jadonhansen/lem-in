PROGRAM = lem-in
LIB = libft
SRCS = lemin.c
FLAGS = -Wall -Werror -Wextra

all: $(LIB) $(PROGRAM)

$(LIB): relib cleanlib

$(PROGRAM):
		gcc -o $(PROGRAM) $(FLAGS) $(SRCS) -lft -L./libft -I

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(PROGRAM)
	/bin/rm -f ./libft/libft.a

re: fclean all

relib:
	make -C ./libft re

cleanlib:
	make -C ./libft clean