NAME = so_long

SRCS = so_long.c read_map.c print_map.c get_next_line.c \
			get_next_line_utils.c key_press.c check_exit.c \
			ft_free.c ft_itoa.c ft_calloc.c ft_bzero.c \
			ft_memset.c ft_error.c

INCLUD = so_long.h \
			mlx.h

CC = clang
RM = rm -f
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror -MMD
LIB = -L. -lmlx -framework OpenGL -framework AppKit

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all:	${NAME}

-include $(DEPS)
${NAME}:	${OBJS}
	make -C ./mlx all
	cp ./mlx/libmlx.a .
	$(CC) $(SRCS) $(LIB) -o $(NAME)

clean:
			make -C ./mlx clean
			${RM} ${OBJS}
			${RM} ${DEPS}

fclean: clean
			make -C ./mlx clean
			${RM} ${NAME} libmlx.a

re: fclean
	${MAKE}

.PHONY: all clean fclean re
