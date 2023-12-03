##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =   src/main.c\
			src/init.c\
			src/menu.c\
			src/game.c\
			src/score.c\
			src/events.c\
			src/sprites.c\
			src/gameover.c\
			src/put_fonction.c\

OBJ	    =	$(SRC:.c=.o)

NAME    =	my_hunter

CFLAGS  =	-g -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
