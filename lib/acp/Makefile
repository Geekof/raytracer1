##
## Makefile for misc in /home/arthur/delivery/.misc
##
## Made by Arthur Philippe
## Login   <arthur@epitech.net>
##
## Started on  Mon Nov  7 11:39:45 2016 Arthur Philippe
## Last update Wed Jan 25 18:53:54 2017 Arthur Philippe
##

CC	=	gcc

RM	=	rm -f

NAME	=	libacp.a

SRCS	=	src/print/my_printf.c		\
		src/print/disp.c		\
		src/print/disp1.c		\
		src/print/disp2.c		\
		src/print/disp3.c		\
		src/print/utilities.c		\
		src/print/utilities1.c		\
		src/print/flags1.c		\
		src/print/flags2.c		\
		src/print/flags3.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CFLAGS	+=	-I include/

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
