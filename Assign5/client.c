//NOTE:
// To Compile:
//Type cmd "make" in the directory .
//in two seperate termianl run the cmd ./client and ./server.
//Use the client for input and the server for output

#include <stdio.h>
#include <stdlib.h>
#include "fifo1.h"
#define QUIT "quit"

int main()
{
    int publicfifo, nbytes;
    char text[PIPE_BUF];

    /*Opening PUBLIC fifo in WRITE ONLY mode*/
    if ((publicfifo = open(PUBLIC, O_WRONLY)) < 0)
    {
        perror(PUBLIC);
        exit(1);
    }
    /*Writes to the pipe*/
    while (1)
    {
        printf("Please give a number (-1 to exit):");
        fflush(stdout);              //Flushes the console stream
        memset(text, 0x0, PIPE_BUF); //sets value of text to 0.
        nbytes = read(fileno(stdin), text, PIPE_BUF);
        write(publicfifo, text, PIPE_BUF);

        if (! strncmp("-1", text, nbytes - 1)) //if -1 is read, the program exits
            break;
    }
    close(publicfifo);
}
