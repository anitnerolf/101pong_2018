##
## EPITECH PROJECT, 2018
## 101pong_2018
## File description:
## Makefile
##

SRC	=	101_pong.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

CFLAGS	=	-lm

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
