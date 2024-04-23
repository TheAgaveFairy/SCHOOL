CC = gcc
CFLAGS = -Wall -Wextra -std=c89 -c
FINAL = -Wall -Wextra -std=c89

sort: main.o student.o
	$(CC) $(FINAL) main.o student.o -o sort

main.o: main.c student.h
	$(CC) $(CFLAGS)  main.c -o main.o

student.o: student.c student.h
	$(CC) $(CFLAGS) student.c -o student.o

clean:
	rm -rf *.o
	rm -f sort