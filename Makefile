##############
#			 #
#   Lem-in   #
#			 #
##############

NAME = lem-in
NAME_V = viz
LIB = libft
CC = gcc
FLAGS = -Wall -Werror -Wextra
LSRC_DIR = ./srcs/lem_in/
LOBJ_DIR = ./srcs/lem_in/
VSRC_DIR = ./srcs/viz/
VOBJ_DIR = ./srcs/viz/
INC_DIR = ./includes/
OPTIONS = -I$(INC_DIR) -I./libft -lft -L./libft
LHDR = ./includes/lem_in.h
VHDR = ./includes/viz.h

OBJ = $(LOBJ_DIR)lem_in.o $(LOBJ_DIR)read_map.o $(LOBJ_DIR)basic_errors_one.o
OBJ += $(LOBJ_DIR)basic_errors_two.o $(LOBJ_DIR)error_output.o $(LOBJ_DIR)content_ops_one.o
OBJ += $(LOBJ_DIR)rooms_ops.o $(LOBJ_DIR)advanced_check_one.o $(LOBJ_DIR)content_ops_two.o
OBJ += $(LOBJ_DIR)advanced_check_two.o

OBJ_V = $(VOBJ_DIR)v_main.o $(VOBJ_DIR)v_init.o $(VOBJ_DIR)v_event.o $(VOBJ_DIR)v_drawing.o
OBJ_V += $(VOBJ_DIR)v_helpers.o $(VOBJ_DIR)v_error.o

all: $(LIB) $(NAME) #$(NAME_V)

$(LIB): relib cleanlib
	@echo "[$(LIB)] compiled"

#%.o: $(SRC_DIR)%.c $(HDR)
#	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(FLAGS) $(OPTIONS) $(OBJ)
	@echo "[$(NAME)] compiled"

#$(NAME_V): $(OBJ_V)
#	@$(CC) -o $(NAME_V) $(FLAGS) $(OPTIONS) $(OBJ_V)
#	@echo "[$(NAME_V)] compiled"

debug: $(LIB)
	@$(CC) -o $(NAME) $(OPTIONS) ./srcs/lem_in/*.c -g
	@echo "Debug binary compiled"

cdebug:
	@/bin/rm -rf ./lem-in.dSYM
	@echo "Debug cleaned"

clean:
	@/bin/rm -f $(LOBJ_DIR)*.o
	@/bin/rm -f $(VOBJ_DIR)*.o
	@echo "Object files removed"

fclean: clean
	@/bin/rm -f $(NAME)
#	@/bin/rf -f $(NAME_V)
	@echo "[$(NAME)] & [$(NAME_V)] removed"

re: fclean all

relib:
	@$(MAKE) -C ./libft re

cleanlib:
	@$(MAKE) -C ./libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./libft fclean