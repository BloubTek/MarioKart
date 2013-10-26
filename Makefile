##
## Makefile for   in /home/barroq_t//Rush/mariokart
## 
## Made by thomas barroqueiro
## Login   <barroq_t@epitech.net>
## 
## Started on  Fri Oct 25 22:18:15 2013 thomas barroqueiro
## Last update Sat Oct 26 14:29:32 2013 thomas barroqueiro
##

NAME	=	bin/MarioKart

CC	=	gcc

RM	=	rm -f

SRC	=	sources/main.c \
		sources/obstacles_and_bonus.c \
		sources/turn.c \
		sources/algo.c \
		sources/move_wall.c \
		sources/create.c \
		sources/display.c \
		sources/raw.c \
		sources/func.c \
		sources/xfunc.c \
		sources/nbr.c

OBJS	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) -lncurses

clean	:	
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re