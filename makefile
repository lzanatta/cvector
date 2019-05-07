VPATH = cvector example

OBJS = obj/example/test_static.o \
       obj/cvector/svector.o \
       obj/cvector/nvector.o

OBJS_DEBUG = obj/example/test_static_debug.o \
             obj/cvector/svector_debug.o \
             obj/cvector/nvector_debug.o

BINARY_RELEASE = bin/test_static

BINARY_DEBUG = bin/test_static_debug

CC = gcc
CFLAGS = -Wunreachable-code -pedantic -Wextra -Wall -std=c11
INCLUDES = -I"../cvector/"

# Setup clean for Windows
ifeq ($(OS),Windows_NT)
    RM = del /Q
    OBJ_FILES = $(subst /,\,$(OBJS))
    OBJ_FILES_DEBUG = $(subst /,\,$(OBJS_DEBUG))
    BIN_RELEASE = $(subst /,\,$(addsuffix .exe,$(BINARY_RELEASE)))
    BIN_DEBUG = $(subst /,\,$(addsuffix .exe,$(BINARY_DEBUG)))
else
    RM = -rm
    OBJ_FILES = $(OBJS)
    OBJ_FILES_DEBUG = $(OBJS_DEBUG)
    BIN_RELEASE = $(BINARY_RELEASE)
    BIN_DEBUG = $(BINARY_DEBUG)
endif

# ifeq ($(OS),Windows_NT)
#     RM = del /Q
#     fix_path = $(subst /,\,$1)
#     BIN_RELEASE = $(addsuffix .exe,$(BINARY_RELEASE))
#     BIN_DEBUG = $(addsuffix .exe,$(BINARY_DEBUG))
# else
#     RM = -rm
#     fix_path = $1
# endif

# Targets
.PHONY: clean
.DEFAULT_GOAL := test_static

# Release build
test_static: test_static.o svector.o nvector.o
	$(CC) -o $(BINARY_RELEASE) $(OBJS) -s

test_static.o: test_static.c svector.h nvector.h
	$(CC) $(CFLAGS) -O2 $(INCLUDES) -c example/test_static.c -o obj/example/test_static.o

svector.o: svector.c svector.h
	$(CC) $(CFLAGS) -O2 $(INCLUDES) -c cvector/svector.c -o obj/cvector/svector.o

nvector.o: nvector.c nvector.h
	$(CC) $(CFLAGS) -O2 $(INCLUDES) -c cvector/nvector.c -o obj/cvector/nvector.o

# Debug build
debug: test_static_debug.o svector_debug.o nvector_debug.o
	$(CC) -o $(BINARY_DEBUG) $(OBJS_DEBUG)

test_static_debug.o: test_static.c svector.h nvector.h
	$(CC) $(CFLAGS) -g $(INCLUDES) -c example/test_static.c -o obj/example/test_static_debug.o

svector_debug.o: svector.c svector.h
	$(CC) $(CFLAGS) -g $(INCLUDES) -c cvector/svector.c -o obj/cvector/svector_debug.o

nvector_debug.o: nvector.c nvector.h
	$(CC) $(CFLAGS) -g $(INCLUDES) -c cvector/nvector.c -o obj/cvector/nvector_debug.o

clean:
	$(RM) $(BIN_RELEASE) $(BIN_DEBUG) $(OBJ_FILES) $(OBJ_FILES_DEBUG)

# clean:
# 	$(RM) $(call fix_path,$(BIN_RELEASE)) $(call fix_path,$(BIN_DEBUG)) \
# 	$(call fix_path,$(OBJ_FILES)) $(call fix_path,$(OBJ_FILES_DEBUG))
