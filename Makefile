NAME = libftprintf.a

NAMELIBFT = libft.a

LIBDIR = ./include/

SRCDIR = ./src/

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(LIBDIR)

SRC = ft_printf.c \
		print_c.c \
		print_d.c \
		print_p.c \
		print_per.c \
		print_s.c \
		print_u.c \
		print_x.c \
		utils.c

SRCS = $(addprefix ${SRCDIR}, ${SRC})

OBJ_SRCS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRCS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ_SRCS)

bonus: $(NAME)

clean:
	make -C ./libft clean
	rm -rf $(OBJ_SRCS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all
