CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = calculadora-t

SRC = src/calculadora-t.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

