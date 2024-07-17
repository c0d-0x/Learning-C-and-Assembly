# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Wformat-security
# LIBS = 
MAIN = main.c

# Source and object files
CFILES = ./src/*.c
OBJFILES = *.o  

# Target binaries
BIN = ./bin/Linked_list_test

all: $(BIN)

# Build executable
$(BIN): $(OBJFILES)
	$(CC) $(CFLAGS) $(LIBS) $(MAIN) -o $@ $^

# Compile source files
$(OBJFILES): $(CFILES)
	$(CC) $(CFLAGS) -c $^ 

clean:
	rm $(BIN) $(OBJFILES)
start:
	 $(BIN)
