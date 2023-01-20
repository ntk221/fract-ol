CC 	   = gcc 
FLAGS  = -Wall -Werror -Wextra

NAME   = Mandelbrot
MLXDIR = ../../minilibx-linux
XLIB   = /opt/X11/lib
XLIBINC = /opt/X11/include/X11
SRCS = main.c utils.c mouse_hooks.c init.c complex.c fractol.c
OBJS = $(SRCS:%c=%o)


$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L$(MLXDIR) -L$(XLIB) -lXext -lX11 -lmlx -I$(MLXDIR) -I$(XLIBINC) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -I$(MLXDIR) -I$(XLIBINC) $(SRCS) -c

fclean: clean
	rm $(NAME)

re: fclean $(NAME)

clean:
	rm $(OBJS)

test:
	gcc test_complex.c complex.c -o complex_test
	./complex_test
	rm complex_test
