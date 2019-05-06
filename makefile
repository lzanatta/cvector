VPATH = cvector example

OBJS = obj/example/test_static.o \
       obj/cvector/svector.o \
       obj/cvector/nvector.o

CC = gcc
CFLAGS = -Wunreachable-code -pedantic -Wextra -Wall -std=c11 -O2 -I"../cvector/"

test_static: test_static.o svector.o nvector.o
	$(CC) -o bin/test_static $(OBJS) -s

test_static.o: test_static.c svector.h
	$(CC) $(CFLAGS) -c example/test_static.c -o obj/example/test_static.o

svector.o: svector.c svector.h
	$(CC) $(CFLAGS) -c cvector/svector.c -o obj/cvector/svector.o

nvector.o: nvector.c nvector.h
	$(CC) $(CFLAGS) -c cvector/nvector.c -o obj/cvector/nvector.o
