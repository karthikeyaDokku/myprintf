CC = gcc

CFLAGS = -Wall -Wextra

TARGET = my_printf

SRC = main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
