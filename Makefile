# C Makefile using gcc and gdb

CC = gcc
CFLAGS = -Wall -Wextra -pthread
LIBS = -lcommons
INCLUDES = -I ./include/ -I ./lib/include
SOURCES = ./src/*.c ./lib/src/*.c


OUTPUT = test.exe

.PHONY: compile debug clean

compile:
	$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES) $(LIBS) -o $(OUTPUT)

debug:
	$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES) -g3 -o $(OUTPUT) && gdb -se $(OUTPUT)

clean:
	$(RM) ./$(OUTPUT)
