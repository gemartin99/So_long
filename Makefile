NAME = so_long

BONUS_NAME = so_long_bonus

GREEN := \033[0;92m

SRCS = so_long.c read_map.c print_map.c get_next_line.c \
			get_next_line_utils.c key_press.c check_exit.c \
			ft_free.c ft_itoa.c ft_calloc.c ft_bzero.c \
			ft_memset.c ft_error.c

BONUS = so_long_bonus.c read_map_bonus.c print_map_bonus.c get_next_line_bonus.c \
			get_next_line_utils_bonus.c key_press_bonus.c check_exit_bonus.c \
			ft_free_bonus.c ft_itoa_bonus.c ft_calloc_bonus.c ft_bzero_bonus.c \
			ft_memset_bonus.c ft_error_bonus.c change_sprite_bonus.c

INCLUD = so_long.h \
			mlx.h

INCLUD_BNS = so_long_bonus.h \
			mlx.h

CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror -MMD
LIB = -L. -lmlx -framework OpenGL -framework AppKit

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
BONUS_OBJECTS = ${BONUS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))
DEPS2 = $(addsuffix .d, $(basename $(BONUS)))

all:	${NAME}

-include $(DEPS)
${NAME}:	${OBJS}
	make -C ./mlx all
	cp ./mlx/libmlx.a .
	$(CC) $(SRCS) $(LIB) -o $(NAME)
	@echo "$(GREEN)So_long compiled successfully.$(DEF_COLOR)"

-include $(DEPS2)
bonus: ${BONUS_OBJECTS}
		@touch $@
		make -C ./mlx all
		cp ./mlx/libmlx.a .
		$(CC) $(BONUS) $(LIB) -o $(BONUS_NAME)
		@echo "$(GREEN)So_long bonus compiled successfully.$(DEF_COLOR)"

clean:
			make -C ./mlx clean
			${RM} ${OBJS} ${BONUS_OBJECTS}
			${RM} ${DEPS} ${DEPS2}

fclean: clean
			${RM} bonus
			${RM} ${NAME} ${BONUS_NAME} libmlx.a
			@echo "$(GREEN)Objects and executable cleaned successfully.$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
