##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC		=	src/bsq_find.c		\
			src/bsq_init.c		\
			src/bsq_src.c		\
			src/main.c		\
			src/bsq_display.c	\
			src/bsq.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include
CFLAGS	+=	-Wall -Wextra

NAME	=	bsq

all:		$(NAME) clean

$(NAME):	$(OBJ)
		@echo "OBJ files created"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@echo "$(NAME) compiled"

tests_run:
		make -C ./tests/
clean:
		@$(RM) $(OBJ)
		@echo "OBJ files removed"

fclean:
		@$(RM) $(NAME)
		@echo "Binary file removed"

re:		fclean all

.PHONY:		all clean fclean re
