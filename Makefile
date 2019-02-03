##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC 	= 	main.c 				\
			src/utils.c			\
			src/utils2.c		\
			src/utils3.c		\
			src/utils4.c		\
			src/sprite.c		\
			src/linked_list.c	\
			src/event.c			\
			src/init_data.c		\
			src/init_data2.c	\
			src/init_data3.c	\
			src/init_obj.c		\
			src/init_game.c		\
			src/player.c		\
			src/map.c			\
			src/collide.c		\
			src/menu.c			\
			src/menu2.c			\

OBJ		=	$(SRC:.c=.o)

NAME 	=	my_runner

RM 		=	rm -rf

RM_TRASH =	*.o *~ *.gcno *.gcda libmy.a *.gch

CFLAGS	= 	-lm -Wextra -g -W -Wall -O2

CLFLAGS = 	-L lib/my/ -lmy

CSFML   = 	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C lib/my/ && gcc $(SRC) -o $(NAME) $(CFLAGS) $(CSFML) $(CLFLAGS)

clean:
	$(RM) $(RM_TRASH)
	cd src && $(RM) $(RM_TRASH)
	cd lib/my/ && $(RM) $(RM_TRASH)
	cd include && $(RM) $(RM_TRASH)


fclean: clean
	$(RM) $(NAME)

re: fclean all
