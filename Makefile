NAME	= fractol

SRCS	= main.c utils.c mouse_hooks.c init.c complex.c fractol.c set_arg.c draw.c hooks.c
OBJS	= $(SRCS:%c=%o)

CC			= gcc 
CFLAGS  = -Wall -Werror -Wextra

MLXDIR		= minilibx-linux
MLX				= $(MLXDIR)/libmlx_Linux.a
LIBFTDIR 	= libft
LIBFLAGS	= -lmlx_Darwin -framework OpenGL -framework AppKit -lXext -lX11 -lm

ifeq ($(shell uname), Darwin)
MLX = $(MLXDIR)/libmlx_Darwin.a
XLIBDIR		= /usr/X11R6/lib
XLIBINC		= /usr/X11/include
LIBFLAGS	= -lmlx_Darwin -framework OpenGL -framework AppKit -lXext -lX11 -lm
else
XLIBDIR		= /usr/lib
LIBFLAGS  = -lmlx_Linux -lXext -lX11 -lm
endif

.PHONY: fclean re clean all

all: $(NAME)

$(NAME): $(OBJS)
	- make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -L$(MLXDIR) -L$(XLIBDIR) -I$(MLXDIR) $(LIBFLAGS) -lft

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I$(MLXDIR) -I$(XLIBINC) $? -c 
	@touch $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

clean:
	@rm -f $(OBJS)

test:
	@gcc test_complex.c complex.c -o complex_test
	@./complex_test
	@rm complex_test
