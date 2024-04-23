CC = gcc
CFLAGS = -Wall -Wextra -std=c89 -c
FINAL = -Wall -Wextra -std=c89

p2: main.o linkedlist.o
	$(CC) $(FINAL) main.o linkedlist.o -o p2

main.o: main.c linkedlist.h
	$(CC) $(CFLAGS)  main.c -o main.o

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) linkedlist.c -o linkedlist.o
	
clean:
	rm -rf *.o
	rm -f p2