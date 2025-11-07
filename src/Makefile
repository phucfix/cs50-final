# Directories
IDIR = ../include
ODIR = obj
LDIR = ../lib

# Compiler and flags
CC = gcc
CFLAGS = -I$(IDIR)
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Automatically find source and header files
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, $(ODIR)/%.o, $(SRC))
DEPS := $(wildcard $(IDIR)/*.h)

# Default target
game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Object file build rule
$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean up
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o main

