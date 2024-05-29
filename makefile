# Define the compiler
CC = gcc

# Define compiler flags
CFLAGS = -Wall -Wextra -Werror

# Define the target executable
TARGET = main

# Define the source files
SRCS = main_JOinParis.c functions_JOinParis.c imports_and_variables_JOinParis.c

# Define the object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Target to install necessary packages
install:
	sudo apt-get update
	sudo apt-get install -y build-essential gnuplot

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Rule to clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all install run clean
