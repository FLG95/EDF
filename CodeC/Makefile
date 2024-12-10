# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c11 -Iinclude -g

LIBS = -lncursesw


# Source files
SRC = main.c createAvl.c parcours.c affichage.c createData.c fonctionUtile.c outFile.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable
TARGET = exe


# Linking the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Default target
all: $(TARGET)
	./$(TARGET) $(ARGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -f $(OBJ) $(TARGET)