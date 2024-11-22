# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c11 -Iinclude

LIBS = -lncurses


# Source files
SRC = main.c creerAvl.c parcours.c affichage.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable
TARGET = exe


# Linking the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Default target
all: $(TARGET)
	./exe

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -f $(OBJ) $(TARGET)