#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* 
* Name: Lakiel Wade
* CSU ID: 2601283
* CIS 340: Assignment #3
* Description: main class handles looping and communicate with Node.c
*/

struct List *head;
struct List *tail;
/*Handles user input, and calls function from node to create linked list.*/
int main(int argc, char **argv)
{
	int value;
	head = NULL;
	tail = NULL;
	
	if (argc > 1)
	{
		int list_size = atoi(argv[1]);

		for (int x = 0; x < list_size; x++)
		{
			printf("Enter integer %d: ", x);
			scanf("%d", &value);

			head = insertnode(head, value);
		}
		tail = GetFirstNode(head);
		PrintList(tail);
	}
	else
	{
		printf("No size was given for linked list\n");
	}
}