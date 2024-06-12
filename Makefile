NAME = philo
CC = clang
CFLAGS = -Wall -Werror -Wextra -g -pthread -fsanitize=thread
SRC = src/checker.c src/dinner.c src/init.c src/main.c src/messages.c src/philo.c src/routine.c src/utils.c src/philo2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

# -fsanitize=thread -g -O1
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

src/%.o:	src/%.c
			@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@$(RM) -r $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
