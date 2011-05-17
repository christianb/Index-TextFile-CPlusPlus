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

compile: $(OBJECTS)
		mkdir -p $(BIN); $(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) 

main.o: $(SRC)/main.cpp
		$(CC) -c $(CFLAGS) $(SRC)/main.cpp -o $(SRC)/main.o 

cmdline.o: $(SRC)/cmdline.cpp 
		$(CC) -c $(CFLAGS) $(SRC)/cmdline.cpp -o $(SRC)/cmdline.o 

index.o: $(SRC)/index.cpp
		$(CC) -c $(CFLAGS) $(SRC)/index.cpp -o $(SRC)/index.o 

controller.o: $(SRC)/controller.cpp
		$(CC) -c $(CFLAGS) $(SRC)/controller.cpp -o $(SRC)/controller.o 

indexparser.o: $(SRC)/indexparser.cpp
		$(CC) -c $(CFLAGS) $(SRC)/indexparser.cpp -o $(SRC)/indexparser.o 

stringutil.o: $(SRC)/stringutil.o
	$(CC) -c $(CFLAGS) $(SRC)/stringutil.cpp -o $(SRC)/stringutil.o 

fileutil.o: $(SRC)/fileutil.o
	$(CC) -c $(CFLAGS) $(SRC)/fileutil.cpp -o $(SRC)/fileutil.o 

clean:	FORCE
		rm -f $(OBJECTS)

valgrind: clean compile
		valgrind --leak-check=full $(TARGET)

exec: clean compile
	$(TARGET) -t out.txt input.txt input3.txt
	

doc: FORCE
		doxygen

FORCE:
