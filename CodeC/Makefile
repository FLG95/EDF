# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c11 -Iinclude

LIBS = -lncursesw


# Source files
SRC = main.c creerAvl.c parcours.c affichage.c creerDonnees.c fonctionUtile.c outFile.c

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