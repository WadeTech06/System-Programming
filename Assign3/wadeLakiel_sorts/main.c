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
struct List *sorted; //pointer to head node.

int main() {
int value;
head = NULL;
tail = NULL;
sorted = NULL;
	
	printf("Please input a number 0 to exit: ");
	scanf("%d",&value);
	if(value != 0)
	{	
		head = Insert(head,value);
		while (value != 0) 
		{
			printf("Please input a number 0 to exit: ");
			scanf("%d",&value);
			if(value != 0)
			{				
				head = Insert(head ,value);
			}			
		}
			tail = GetFirstNode(head);
			PrintList(tail);

			sorted = quicksort(tail);
			PrintList(sorted);
	}
	else 
	{
		printf("No number is given.\n");
	}	
}

