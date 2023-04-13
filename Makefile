# Compiler options
CC = g++
CFLAGS = -Wall -std=c++11

# Directories
SRCDIR = src
OBJDIR = build
RAYLIBDIR = $(HOME)/raylib/src

# Libraries and linking
LIBS = -lraylib -lm -lpthread -ldl -lX11

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Output binary
TARGET = $(OBJDIR)/mygame

all: $(TARGET)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -L$(RAYLIBDIR) $^ -o $@ $(LIBS)

# Clean build directory
clean:
	rm -f $(OBJDIR)/*

# Run the program
run:
	$(MAKE) all
	$(TARGET)

.PHONY: all clean run
