NAME = push_swap

NAME_BONUS = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = push_swap.c sort_3_and_5_nodes.c push.c ft_atoll.c butterfly.c error_functions.c \
		ft_lst_functions.c split.c validation.c reverse_rotate_stack.c rotate_stack.c \
		swap_top_2_elements.c

BONUS = sort_3_and_5_nodes.c push.c ft_atoll.c butterfly.c error_functions.c \
		ft_lst_functions.c split.c validation.c reverse_rotate_stack.c rotate_stack.c \
		swap_top_2_elements.c bonus.c bonus_2.c get_next_line.c get_next_line_utils.c

OBJS = ${SRC:.c=.o}

Bonus_OBJS = ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} push_swap.h Makefile
	${CC} ${FLAGS} ${OBJS} -o ${NAME} 

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${Bonus_OBJS}  push_swap.h Makefile
	${CC} ${FLAGS} ${Bonus_OBJS} -o ${NAME_BONUS}

%.o:%.c
	${CC} ${FLAGS} -c  $< -o $@

clean:
	rm -f ${OBJS} ${Bonus_OBJS}

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}

re: fclean all bonus

.PHONY: all clean fclean re bonus
