# Aditi Nautiyal

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = pomodoro

all: $(TARGET)

$(TARGET): pomodoro.c
	$(CC) $(CFLAGS) -o $(TARGET) pomodoro.c

clean:
	rm -f $(TARGET)
