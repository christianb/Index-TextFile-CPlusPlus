# This is a makefile created by Christian Bunk
# Last update 02.05.2011

# Define C Compiler
CC = c++
# Define standard flags
CFLAGS = -Wall -g
# Files to be compiled
OBJECTS = $(SRC)/main.o $(SRC)/cmdline.o $(SRC)/index.o $(SRC)/controller.o

CD = cd

# Name and Target of the Application 
NAME = bin/project1

SRC = src

compile: $(OBJECTS)
		mkdir -p bin/; $(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)  

main.o: $(SRC)/main.cpp
		$(CC) -c $(CFLAGS) $(SRC)/main.cpp

cmdline.o: $(SRC)/cmdline.cpp 
		$(CC) -c $(CFLAGS) $(SRC)/cmdline.cpp

index.o: $(SRC)/index.cpp
		$(CC) -c $(CFLAGS) $(SRC)/index.cpp
		
controller.o: $(SRC)/controller.cpp
		$(CC) -c $(CFLAGS) $(SRC)/controller.cpp

clean:	FORCE
		rm -f $(OBJECTS)

valgrind: clean compile
		valgrind --leak-check=full ./$(NAME)

exec: clean compile
	./$(NAME) -p out.txt input3.txt input.txt
	

doc: FORCE
		doxygen

FORCE:
