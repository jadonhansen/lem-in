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
INC_DIR = ./includes
OPTIONS = -I./includes -I./libft -lft -L./libft
LHDR = ./includes/lem_in.h
L2HDR = ./includes/lem_in2.h
VHDR = ./includes/viz.h
OTHER_LIB = -L/homes/$(USER)/.brew/lib -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image
INCLUDES = -I/homes/$(USER)/.brew/include/
# CD_SDL_L = -L/usr/local/lib -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image
# CD_SDL_I = -I/usr/local/include/

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
WARN_COLOR=\x1b[33;01m

OBJ = $(LOBJ_DIR)lem_in.o $(LOBJ_DIR)read_map.o $(LOBJ_DIR)basic_errors_one.o
OBJ += $(LOBJ_DIR)basic_errors_two.o $(LOBJ_DIR)error_out_one.o $(LOBJ_DIR)content_ops_one.o
OBJ += $(LOBJ_DIR)rooms_ops_one.o $(LOBJ_DIR)advanced_check_one.o $(LOBJ_DIR)content_ops_two.o
OBJ += $(LOBJ_DIR)advanced_check_two.o $(LOBJ_DIR)rooms_ops_two.o $(LOBJ_DIR)error_out_two.o
OBJ += $(LOBJ_DIR)algo_one.o $(LOBJ_DIR)algo_two.o $(LOBJ_DIR)queue_ops.o $(LOBJ_DIR)path_ops.o

OBJ_V = $(VOBJ_DIR)v_main.o $(VOBJ_DIR)v_viz.o $(VOBJ_DIR)v_event.o $(VOBJ_DIR)v_drawing.o
OBJ_V += $(VOBJ_DIR)v_helpers.o $(VOBJ_DIR)v_error.o $(VOBJ_DIR)v_moves.o $(VOBJ_DIR)v_ants.o
OBJ_V += $(VOBJ_DIR)v_parse.o $(VOBJ_DIR)v_valf.o $(VOBJ_DIR)v_traversal.o $(VOBJ_DIR)v_val.o
OBJ_V += $(VOBJ_DIR)v_disp.o $(VOBJ_DIR)v_path.o $(VOBJ_DIR)v_room.o $(VOBJ_DIR)v_link.o

all: $(LIB) $(NAME) $(NAME_V)

$(LIB): relib cleanlib
	@echo "$(OK_COLOR)[$(LIB)] compiled$(NO_COLOR)"

#%.o: $(SRC_DIR)%.c $(HDR)
#	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(FLAGS) $(OPTIONS) $(OBJ)
	@echo "$(OK_COLOR)[$(NAME)] compiled$(NO_COLOR)"

$(NAME_V): $(OBJ_V)
	@$(CC) -o $(NAME_V) $(FLAGS) $(OTHER_LIB) $(INCLUDES) $(OPTIONS) $(OBJ_V)
#	@$(CC) -o $(NAME_V) $(FLAGS) $(OPTIONS) $(OBJ_V) $(CD_SDL_L) $(CD_SDL_I)
	@echo "$(OK_COLOR)[$(NAME_V)] compiled$(NO_COLOR)"

debug: $(LIB)
	@$(CC) -o $(NAME) $(OPTIONS) ./srcs/lem_in/*.c -g
	@echo "$(OK_COLOR)Debug binary compiled$(NO_COLOR)"

cdebug:
	@/bin/rm -rf ./lem-in.dSYM
	@echo "$(WARN_COLOR)Debug cleaned$(NO_COLOR)"

clean:
	@/bin/rm -f $(LOBJ_DIR)*.o
	@/bin/rm -f $(VOBJ_DIR)*.o
	@echo "$(WARN_COLOR)Object files removed$(NO_COLOR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAME_V)
	@echo "$(WARN_COLOR)[$(NAME)] & [$(NAME_V)] removed$(NO_COLOR)"

re: fclean all

relib:
	@$(MAKE) -C ./libft re

cleanlib:
	@$(MAKE) -C ./libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./libft fclean