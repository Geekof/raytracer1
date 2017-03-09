##
## Makefile for raytracer1 in /home/arthur/delivery/raytracer1/
##
## Made by Arthur Philippe
## Login   <arthur.philippe@epitech.eu>
##
## Started on  Sun Feb 12 17:33:18 2017 Arthur Philippe
## Last update Wed Mar  8 21:27:30 2017 Arthur Philippe
##

CC	=	gcc

RM	=	rm -f

NAME	=	raytracer1

SRCS	=	src/main.c				\
		src/open_window.c			\
		src/my_put_pixel.c			\
		src/calc_dir_vector.c			\
		src/data_nuke.c				\
		src/sphere.c				\
		src/plane.c				\
		src/cone.c				\
		src/rotate.c				\
		src/cylinder.c				\
		src/translate.c				\
		src/light.c				\
		src/color_modifier.c			\
		src/raytrace_scene.c			\
		src/obj_fctn_shunter.c			\
		src/utilities.c				\
		src/utils.c				\
		src/data_gathering/load_data.c		\
		src/data_gathering/objects_creation.c	\
		src/data_gathering/match.c		\
		src/data_gathering/fd_errors.c		\
		src/data_gathering/get_next_line.c	\
		src/data_gathering/list.c		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wextra -Wall

##CFLAGS	+=	-Werror

CFLAGS	+=	-I include/

LDFLAGS	=	-L./lib/acp -lacp -lc_graph_prog -lm

all: make_acp_print $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

make_acp_print:
	$(MAKE) -C lib/acp

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C lib/acp

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib/acp

re: fclean all

.PHONY: all clean fclean re lib_make
