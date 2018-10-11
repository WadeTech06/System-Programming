CC=gcc -g -Wall
CFLAGS=-I.
DEPS =fifo.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: assign5_server assign5_client

assign5_server: server.o
	$(CC) -o $@ $^ $(CFLAGS)

assign5_client: client.o
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o all

# Use –c flag to create .o file
# Use –l flag to link a library file, e.g., -lm for
# by putting object files server.o client.o make knows it must first compile the .c version indivdually


#to build and compile navigate to folder and run "make"
