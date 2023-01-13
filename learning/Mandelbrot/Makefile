CC 	   = gcc 
FLAGS  = -Wall -Werror -Wextra

NAME   = Mandelbrot
MLXDIR = ../../minilibx-linux
XLIB   = /opt/X11/lib
XLIBINC = /opt/X11/include/X11
SRCS = ./*.c

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME):
	$(CC)  -L$(MLXDIR) -L$(XLIB) -lXext -lX11 -lmlx -I$(MLXDIR) -I$(XLIBINC) -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

fclean:
	rm $(NAME)

re: fclean $(NAME)

test:
	gcc test_complex.c complex.c -o complex_test
	./complex_test
	rm complex_test
