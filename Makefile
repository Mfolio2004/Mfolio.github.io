##
## EPITECH PROJECT, 2020
## makefile
## File description:
## c
##

SRC	=	main.c \
		tools.c \
		Menu/menu.c \
		initialize_struct.c \
		Menu/button.c \
		ennemies.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

LIB	=	-L ./lib/my/ -lmy

all:		$(NAME) clean

$(NAME):	$(OBJ)
		cd lib/my && make
		gcc -o $(NAME) $(OBJ) $(LIB) -lm -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

clean :
		rm -f $(OBJ)

fclean :	clean
		rm -f $(NAME)
		cd lib/my && rm libmy.a

re :		fclean all
