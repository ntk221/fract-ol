CC		= gcc 
CFLAGS  = -Wall -Werror -Wextra

NAME	= fract-ol
MLXDIR	= ../minilibx-linux
XLIB	= /opt/X11/lib
XLIBINC = /opt/X11/include/X11
SRCS	= main.c utils.c mouse_hooks.c init.c complex.c fractol.c set_arg.c draw.c hooks.c
OBJS	= $(SRCS:%c=%o)
RM		= rm -f
LIBFTDIR = libft

.PHONY: fclean re clean all

all: $(NAME)

$(NAME): $(OBJS)
	- make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -L$(LIBFTDIR) -L$(MLXDIR) -L$(XLIB) -lXext -lX11 -lmlx -I$(MLXDIR) -I$(XLIBINC) -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) -lft

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I$(MLXDIR) -I$(XLIBINC) $? -c 
	touch $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

clean:
	$(RM) $(OBJS)

test:
	gcc test_complex.c complex.c -o complex_test
	./complex_test
	rm complex_test
