# This is a makefile created by Christian Bunk
# Last update 29.04.2011

# Define C Compiler
CC = c++
# Define standard flags
CFLAGS = -Wall
# Files to be compiled
OBJECTS = main.o cmdline.o
# Name of the Application 
NAME = ../bin/project1

project1: $(OBJECTS)
		$(CC) $(OBJECTS) -o $(NAME)  

main.o: main.cpp
		$(CC) -c $(CFLAGS) main.cpp

cmdline.o: cmdline.cpp 
		$(CC) -c $(CFLAGS) cmdline.cpp

clean:
	rm $(OBJECTS)