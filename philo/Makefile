
NAME				=	philo

SRC_DIR				=	src
INCLUDES_DIR		= 	includes

SOURCES				= 	$(SRC_DIR)/error.c \
						$(SRC_DIR)/ft_atoi.c \
						$(SRC_DIR)/log.c \
						$(SRC_DIR)/philo_factory.c \
						$(SRC_DIR)/philo_mutex.c \
						$(SRC_DIR)/philo_thread.c \
						$(SRC_DIR)/state.c \
						$(SRC_DIR)/atime.c
MAIN_SOURCES		= 	$(SRC_DIR)/main.c $(SOURCES)
OBJS				= 	$(MAIN_SOURCES:.c=.o)

CFLAGS 				= 	-Wall -Wextra -Werror -pthread
CC 					= 	gcc

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -I ${INCLUDES_DIR} -o $@ $^

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I ${INCLUDES_DIR} $(OBJS) -o $(NAME)

bonus: $(NAME)

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

valgrind:
	valgrind --leak-check=full --track-origins=yes ./philo

test:
	./philo 10 20 10 10 1

.PHONY: all clean fclean re valgrind test
