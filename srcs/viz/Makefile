INCLUDES = -I$(HOME)/.brew/include/
HEADERS = -I$(HOME)/.brew/include/
SDL_L = $(HOME)/.brew/lib/
LIBS = $(HEADERS) -L$(SDL_L) -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image -L../../libft -lft

all:
	gcc $(LIBS)  -I../../includes/ v_main.c v_init.c v_event.c v_error.c v_helpers.c v_drawing.c

test:
	gcc $(LIBS)  -I../../includes/ viz_ref.c
