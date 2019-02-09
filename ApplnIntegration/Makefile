CC = gcc
FLAG_LINK = -c
all: application
application: application.c dll.o
	$(CC) application.c dll.o -o application
dll.o : dll.c
	$(CC) $(FLAG_LINK) dll.c
clean: dll.o application
	rm dll.o application