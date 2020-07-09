INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I..

LIBFT = libft/libft.a

NAME= fdf
SRC = main.c map_display.c math_display.c event.c \
errorcase.c readfile3.c \
command_window.c parallel.c \
readfile4.c

OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./minilibX -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd $(LIBFT)

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all
