# This is a makefile created by Christian Bunk
# Last update 02.05.2011

# Define C Compiler
CC = c++
# Define standard flags
CFLAGS = -Wall
# Files to be compiled
OBJECTS = $(SRC)main.o $(SRC)cmdline.o $(SRC)index.o $(SRC)controller.o

CD = cd

# Name and Target of the Application 
NAME = bin/project1

SRC = ./src/

project1: $(OBJECTS)
		mkdir -p bin/; $(CC) $(OBJECTS) -o $(NAME)  

main.o: $(SRC)main.cpp
		$(CC) -c $(CFLAGS) src/main.cpp

cmdline.o: $(SRC)cmdline.cpp 
		$(CC) -c $(CFLAGS) src/cmdline.cpp

index.o: $(SRC)index.cpp
		$(CC) -c $(CFLAGS) src/index.cpp
		
controller.o: $(SRC)controller.cpp
		$(CC) -c $(CFLAGS) src/controller.cpp

clean:
		rm $(OBJECTS)

valgrind: 
		valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./bin/project1 -i input.txt


doc: FORCE
		doxygen

FORCE:
