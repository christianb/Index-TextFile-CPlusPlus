# Makefile in einem Unterverzeichnis
include Makefile.rules

# program name 
NAME = index

# bin directory
BIN = ./bin

# source directory
SRC = ./src

# target (merge with bin and name)
TARGET = $(BIN)/$(NAME)

DIRS = src/

all: compile link

link: 
	mkdir -p $(BIN); $(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

compile:
	for i in $(DIRS); do make -C $$i; done

clean:
	for i in $(DIRS); do make -C $$i clean; done

valgrind: compile
		valgrind --leak-check=full $(TARGET)

doc: FORCE
		doxygen

FORCE:
