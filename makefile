# This is a makefile created by Christian Bunk
# Last update 02.05.2011

# Define C Compiler
CC = g++
# Define standard flags
CFLAGS = -Wall -Wextra -g -DLexic_Compare -DTwo_Options

# Files to be compiled
OBJECTS = $(SRC)/main.o \
$(SRC)/cmdline.o \
$(SRC)/index.o \
$(SRC)/lexic.o \
$(SRC)/controller.o \
$(SRC)/indexparser.o \
$(SRC)/stringutil.o \
$(SRC)/fileutil.o \

# program name 
NAME = index

# bin directory
BIN = ./bin

# source directory
SRC = ./src

# target (merge with bin and name)
TARGET = $(BIN)/$(NAME)

install: clean compile

compile: main.o cmdline.o index.o lexic.o controller.o indexparser.o stringutil.o fileutil.o
		mkdir -p $(BIN); $(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) 

main.o: $(SRC)/main.cpp
		$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(SRC)/main.o

cmdline.o: $(SRC)/cmdline.cpp 
		$(CC) $(CFLAGS) -c $(SRC)/cmdline.cpp -o $(SRC)/cmdline.o

index.o: $(SRC)/index.cpp
		$(CC) $(CFLAGS) -c $(SRC)/index.cpp -o $(SRC)/index.o

controller.o: $(SRC)/controller.cpp
		$(CC) $(CFLAGS) -c $(SRC)/controller.cpp -o $(SRC)/controller.o

indexparser.o: $(SRC)/indexparser.cpp
		$(CC) $(CFLAGS) -c $(SRC)/indexparser.cpp -o $(SRC)/indexparser.o

stringutil.o: $(SRC)/stringutil.cpp
		$(CC) $(CFLAGS) -c $(SRC)/stringutil.cpp -o $(SRC)/stringutil.o

fileutil.o: $(SRC)/fileutil.cpp
		$(CC) $(CFLAGS) -c $(SRC)/fileutil.cpp -o $(SRC)/fileutil.o

lexic.o: $(SRC)/lexic.cpp
		$(CC) $(CFLAGS) -c $(SRC)/lexic.cpp -o $(SRC)/lexic.o

clean:	FORCE
		rm -f $(OBJECTS)

valgrind: clean compile
		valgrind --leak-check=full $(TARGET)

exec: clean compile
	$(TARGET) -t out.txt input.txt input3.txt
	

doc: FORCE
		doxygen

FORCE:
