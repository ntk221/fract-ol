CC 	   = gcc
FLAGS  = -Wall -Werror -Wextra

NAME   = event
MLXDIR = ../../../minilibx-linux
XLIB   = /opt/X11/lib

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME):
	$(CC)  -L$(MLXDIR) -L$(XLIB) -lXext -lX11 -lmlx -I$(MLXDIR) -framework OpenGL -framework AppKit events.c -o $(NAME)


test:
	gcc test_complex.c complex.c -o complex_test
	./complex_test
	rm complex_test