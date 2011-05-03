# This is a makefile created by Christian Bunk
# Last update 02.05.2011

# Define C Compiler
CC = c++
# Define standard flags
CFLAGS = -Wall
# Files to be compiled
OBJECTS = $(SRC)main.o $(SRC)cmdline.o $(SRC)index.o

CD = cd

# Name and Target of the Application 
NAME = bin/project1

SRC = ./src/

project1: $(OBJECTS)
		mkdir bin/; $(CC) $(OBJECTS) -o $(NAME)  

main.o: $(SRC)main.cpp
		$(CC) -c $(CFLAGS) src/main.cpp

cmdline.o: $(SRC)cmdline.cpp 
		$(CC) -c $(CFLAGS) src/cmdline.cpp

index.o: $(SRC)index.cpp
		$(CC) -c $(CFLAGS) src/index.cpp

clean:
		rm $(OBJECTS)

doc: FORCE
		doxygen

FORCE: