
#include <stdio.h>
#include <stdlib.h>
#include "fifo1.h"
#include<time.h>

int main(int argc, char *argv[])
{
	//variables that will be needed in the program
	int nbytes, dummyfifo, publicfifo, inputnum, key;
	static char buffer[PIPE_BUF];
	srand(time(0));
	key = rand() % 100;

	/*creating the PUBLIC fifo*/
	if (mkfifo(PUBLIC, 0666) < 0)
	{
		perror(PUBLIC);
		exit(1);
	}
	if ((publicfifo = open(PUBLIC, O_RDONLY)) < 0 ||
		(dummyfifo = open(PUBLIC, O_WRONLY | O_NDELAY)) < 0)
	{
		perror(PUBLIC);
		exit(1);
	}

	/*Read the message from PUBLIC fifo*/
	while (1)
	{
		memset(buffer, 0, PIPE_BUF);
		if ((nbytes = read(publicfifo, buffer, PIPE_BUF)) > 0)
		{
			//converts text from char to int and stores as inputnum
			inputnum = atoi(buffer);
			if (inputnum == -1)
				break;

			if (key == inputnum)
			{
				printf("You got it, The key is %d\n",key);
				break;
			}
			else if (key < inputnum)
				printf("The Key is smaller\n");
			else if (key > inputnum)
				printf("The Key is bigger\n");

			fflush(stdout);
		}
		else
			break;
	}
	close(publicfifo);
	unlink(PUBLIC);
	return 0;
}
