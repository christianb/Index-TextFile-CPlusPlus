# Makefile in einem Unterverzeichnis
include Makefile.rules

all: compile link

link: compile
	mkdir -p $(BIN); $(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

compile:
	for i in $(DIRS); do make -C $$i; done

clean:
	for i in $(DIRS); do make -C $$i clean; done

valgrind: compile
		valgrind --leak-check=full $(TARGET)

doc: FORCE
		doxygen

FORCE:
