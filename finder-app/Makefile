# Set the default compiler to gcc, unless CROSS_COMPILE is specified on the command line.
CC := $(CROSS_COMPILE)gcc

# The default target to build the 'writer' application
all: writer

# Target to build the 'writer' executable
writer: writer.o
	$(CC) -o writer writer.o

# Rule to compile the 'writer.c' source file
writer.o: writer.c
	$(CC) -c writer.c -o writer.o

# Clean up build artifacts (remove the 'writer' executable and all .o files)
clean:
	rm -f writer writer.o

# Phony targets to avoid conflicts with file names
.PHONY: all clean

