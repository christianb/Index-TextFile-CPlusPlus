# This is a makefile created by Christian Bunk
# Last update 02.05.2011

# Define C Compiler
CC = c++
# Define standard flags
CFLAGS = -Wall -Wextra -g

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

compile: main cmdline index lexic controller indexparser stringutil fileutil
		mkdir -p $(BIN); $(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) 

main: FORCE
		$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(SRC)/main.o

cmdline: FORCE
		$(CC) $(CFLAGS) -c $(SRC)/cmdline.cpp -o $(SRC)/cmdline.o

index: FORCE
		$(CC) $(CFLAGS) -c $(SRC)/index.cpp -o $(SRC)/index.o

controller: FORCE
		$(CC) $(CFLAGS) -c $(SRC)/controller.cpp -o $(SRC)/controller.o

indexparser: FORCE
		$(CC) $(CFLAGS) -c $(SRC)/indexparser.cpp -o $(SRC)/indexparser.o

stringutil: FORCE
		$(CC) $(CFLAGS) -c $(SRC)/stringutil.cpp -o $(SRC)/stringutil.o

fileutil: FORCE
		$(CC) $(CFLAGS) -c $(SRC)/fileutil.cpp -o $(SRC)/fileutil.o

lexic: FORCE
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
