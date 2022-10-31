NAME = so_long

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

BONUS_NAME = so_long_bonus

GREEN := \033[0;92m

SRCS = ./src/so_long.c ./src/read_map.c ./src/print_map.c ./src/get_next_line.c \
			./src/get_next_line_utils.c ./src/key_press.c ./src/check_exit.c \
			./src/ft_free.c ./src/ft_itoa.c ./src/ft_calloc.c ./src/ft_bzero.c \
			./src/ft_memset.c ./src/ft_error.c

BONUS = ./bns/so_long_bonus.c ./bns/read_map_bonus.c ./bns/print_map_bonus.c ./bns/get_next_line_bonus.c \
			./bns/get_next_line_utils_bonus.c ./bns/key_press_bonus.c ./bns/check_exit_bonus.c \
			./bns/ft_free_bonus.c ./bns/ft_itoa_bonus.c ./bns/ft_calloc_bonus.c ./bns/ft_bzero_bonus.c \
			./bns/ft_memset_bonus.c ./bns/ft_error_bonus.c ./bns/change_sprite_bonus.c

INCLUD = ./inc/so_long.h \
			./inc/mlx.h

INCLUD_BNS = ./inc/so_long_bonus.h \
			./inc/mlx.h

CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror -MMD
LIB = -L. -lmlx -framework OpenGL -framework AppKit

.c.o:
			@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
BONUS_OBJECTS = ${BONUS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))
DEPS2 = $(addsuffix .d, $(basename $(BONUS)))

all:	${NAME}

-include $(DEPS)
${NAME}:	${OBJS}
	@echo "\n${ORANGE}Minilibx compilation $(DEF_COLOR)\n"
	@make -C ./mlx all
	@cp ./mlx/libmlx.a .
	@$(CC) $(SRCS) $(LIB) -o $(NAME)
	@echo "$(GREEN)Created ${NAME} ✓$(DEF_COLOR)\n"

-include $(DEPS2)
bonus: ${BONUS_OBJECTS}
		@echo "\n${ORANGE}Minilibx compilation $(DEF_COLOR)\n"
		@touch $@
		@make -C ./mlx all
		@cp ./mlx/libmlx.a .
		@$(CC) $(BONUS) $(LIB) -o $(BONUS_NAME)
		@echo "$(GREEN)Created ${BONUS_NAME} ✓$(DEF_COLOR)\n"

clean:
			@make -C ./mlx clean
			@${RM} ${OBJS} ${BONUS_OBJECTS}
			@${RM} ${DEPS} ${DEPS2}
			@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"

fclean:
			@make -C ./mlx clean
			@${RM} ${OBJS} ${BONUS_OBJECTS}
			@${RM} ${DEPS} ${DEPS2}
			@${RM} bonus
			@${RM} ${NAME} ${BONUS_NAME} libmlx.a
			@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"


re: fclean all

.PHONY: all clean fclean re
