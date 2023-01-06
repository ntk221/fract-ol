CC = gcc
FLAGS = -Wall -Werror -Wextra

MINLIB  		= ../minilibx-linux/
XLIB				=  /opt/X11/lib
INCLUDE	= ../minilibx-linux/
NAME = test

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L$(MINLIB) -L$(XLIB) -lXext -lX11 -lmlx -I$(INCLUDE) -framework OpenGL -framework AppKit intro.c -o $(NAME)

fclean:$(NAME)
	rm $(NAME)


