# This is a makefile created by Christian Bunk
# Last update 02.05.2011

# Define C Compiler
CC = c++
# Define standard flags
CFLAGS = -Wall
# Files to be compiled
OBJECTS = main.o cmdline.o index.o
# Name and Target of the Application 
NAME = ../bin/project1

project1: $(OBJECTS)
		$(CC) $(OBJECTS) -o $(NAME)  

main.o: main.cpp
		$(CC) -c $(CFLAGS) main.cpp

cmdline.o: cmdline.cpp 
		$(CC) -c $(CFLAGS) cmdline.cpp

index.o: index.cpp
		$(CC) -c $(CFLAGS) index.cpp

clean:
		rm $(OBJECTS)

doc: 
		doxygen