CC			=		gcc

RM			=		rm -f

CFLAGS	=		-I./include -W -Wall -Wextra -pedantic

SRC			=		after.c \
						main.c \
						fct.c \
						next.c

OBJ			=		$(SRC:.c=.o)

NAME		=		./doall

$(NAME)	:		$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

all			:		$(NAME)

clean		:
		$(RM) $(OBJ)

fclean	:		clean
		$(RM) $(NAME)

re			:		fclean all

.PHONY	:		clean fclean re
