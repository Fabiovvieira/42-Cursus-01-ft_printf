NAME = libftprintf.a

NAMELIBFT = libft.a

LIBDIR = ./include/

SRCDIR = ./src/

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $

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

$(info    VAR is $(OBJ_SRCS))

all: $(NAME)

$(NAME): $(OBJ_SRCS)
	ar rc $(NAME) $(OBJ_SRCS)

# clean:
# 	rm -rf $(OBJ_SRCS)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all
