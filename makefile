CC = gcc
C = -c
O = -o
Flag = -Wall -g -c

all: server client

server: Stack.o  server.cpp
	$(CC) server.cpp -lpthread $(O) server

client : client.cpp
	$(CC) client.cpp -lpthread $(O) client

Stack.o: binaryAllocator.o Node.o Stack.c
	$(CC) $(Flag)  Stack.c

binaryAllocator.o: binaryAllocator.c
	$(CC) $(Flag)  binaryAllocator.c

Node.o:	Node.c
	$(CC) $(Flag)  Node.c

.PHONY: clean all

clean:
	rm -f *.o server client