CC = gcc
CFLAGS = -Wall -Wextra -std=c89 -c
FINAL = -Wall -Wextra -std=c89

p2: main.o route-records.o
	$(CC) $(FINAL) main.o route-records.o -o p2

main.o: main.c route-records.h
	$(CC) $(CFLAGS)  main.c -o main.o

route-records.o: route-records.c route-records.h
	$(CC) $(CFLAGS) route-records.c -o route-records.o
	
clean:
	rm -rf *.o
	rm -f p2