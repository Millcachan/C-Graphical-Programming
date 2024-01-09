##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

.SILENT:

SRC     =   src/my.c\
			src/put.c\
			src/free.c\
			src/disp.c\
			src/main.c\
			src/init.c\
			src/loop.c\
			src/clock.c\
			src/usage.c\
			src/planes.c\
			src/towers.c\
			src/script.c\
			src/hitbox.c\
			src/collision.c\
			src/wordarray.c\
			src/simulation.c\

OBJ	    =	$(SRC:.c=.o)

NAME    =	my_radar

CFLAGS  = 	-g -lm -Wall -Wextra -Wconversion -pedantic -Werror

CSFML	= 	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML) $(CFLAGS)
	printf "[%s] — Successfully compiled\n" $(NAME)

clean:
	rm -f $(OBJ)
	rm -f coding-style-reports.log
	rm -f vgcore.*

fclean: clean
	rm -f $(NAME)

re: fclean all
