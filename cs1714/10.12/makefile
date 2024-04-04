CC = gcc
CFLAGS = -Wall -Wextra -std=c89 -lm

all: nt

nt: main.c
	$(CC) $(CFLAGS) -o nt main.c employee.c

clean:
	rm -f nt