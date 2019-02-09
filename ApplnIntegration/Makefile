CC = gcc
FLAG_LINK = -c
GDB_FLAG = -g
all: application
application: application.o dll.o
	$(CC) $(GDB_FLAG) application.o dll.o -o application
dll.o : dll.c application.o
	$(CC) $(FLAG_LINK) $(GDB_FLAG) dll.c -o dll.o
application.o: application.c
	$(CC) $(GDB_FLAG) $(FLAG_LINK) application.c -o application.o
clean: dll.o application
	rm dll.o application.o application