# This is a makefile created by Christian Bunk
# Last update 02.05.2011

# Define C Compiler
CC = c++
# Define standard flags
CFLAGS = -Wall -g

# Files to be compiled
OBJECTS = $(SRC)/main.o \
$(SRC)/cmdline.o \
$(SRC)/index.o \
$(SRC)/controller.o \
$(SRC)/indexparser.o \
$(SRC)/lexic.o \
$(SRC)/stringutil.o \

# program name 
NAME = index

# bin directory
BIN = ./bin

# source directory
SRC = ./src

# target (merge with bin and name)
TARGET = $(BIN)/$(NAME)

install: clean compile

compile: $(OBJECTS)
		mkdir -p $(BIN); $(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) 

main.o: $(SRC)/main.cpp
		$(CC) -c $(CFLAGS) $(SRC)/main.cpp

cmdline.o: $(SRC)/cmdline.cpp 
		$(CC) -c $(CFLAGS) $(SRC)/cmdline.cpp

index.o: $(SRC)/index.cpp
		$(CC) -c $(CFLAGS) $(SRC)/index.cpp
		
controller.o: $(SRC)/controller.cpp
		$(CC) -c $(CFLAGS) $(SRC)/controller.cpp

indexparser.o: $(SRC)/indexparser.cpp
		$(CC) -c $(CFLAGS) $(SRC)/indexparser.cpp
		
lexic.o: $(SRC)/lexic.cpp
	$(CC) -c $(CFLAGS) $(SRC)/lexic.cpp

stringutil.o: $(SRC)/stringutil.o
	$(CC) -c $(CFLAGS) $(SRC)/stringutil.cpp

clean:	FORCE
		rm -f $(OBJECTS)

valgrind: clean compile
		valgrind --leak-check=full $(TARGET)

exec: clean compile
	$(TARGET) -t out.txt input.txt input3.txt
	

doc: FORCE
		doxygen

FORCE:
