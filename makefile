# This is a makefile created by Christian Bunk
# Last update 02.05.2011

# Define C Compiler
CC = c++
# Define standard flags
CFLAGS = -Wall -g
# Files to be compiled
OBJECTS = $(SRC)main.o $(SRC)cmdline.o $(SRC)index.o $(SRC)controller.o

CD = cd

# Name and Target of the Application 
NAME = bin/project1

SRC = ./src/

compile: $(OBJECTS)
		mkdir -p bin/; $(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)  

main.o: $(SRC)main.cpp
		$(CC) -c $(CFLAGS) src/main.cpp

cmdline.o: $(SRC)cmdline.cpp 
		$(CC) -c $(CFLAGS) src/cmdline.cpp

index.o: $(SRC)index.cpp
		$(CC) -c $(CFLAGS) src/index.cpp
		
controller.o: $(SRC)controller.cpp
		$(CC) -c $(CFLAGS) src/controller.cpp

clean:	FORCE
		rm -f $(OBJECTS)

valgrind: clean compile
		valgrind --leak-check=full ./$(NAME) -i output.txt input.txt

exec: clean compile
	./$(NAME) -i output.txt input.txt
	

doc: FORCE
		doxygen

FORCE:
