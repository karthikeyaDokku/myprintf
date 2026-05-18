CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC = main.c _printf.c _putchar.c handlers.c
OBJ = $(SRC:.c=.o)
NAME = my_printf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
