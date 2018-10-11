/* 
* Name: Lakiel Wade
* CSU ID: 2601283
* CIS 340: Assignment #3
* Description: class for Linked List. insertnode, Sort and, Print Lists
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//Create a new linked node and returns its pointer
struct List *createnode(int value)
{
	//allocate memory 12 bytes
	struct List *newNode = (struct List *)malloc(sizeof(struct List));

	//sets value for new node and set next and prev address to null
	*(int *)&newNode->value = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return (newNode);
}

//insert a node at the head of linked list
struct List *insertnode(struct List *head, int value)
{

	//Create new Node
	struct List *newNode = createnode(value);

	if (head == NULL)
	{
		//sets the intial headNode
		head = newNode;
		return (head);
	}
	// sets the next address of head to newNode
	head->next = newNode;
	//sets the prev address of newNode to head
	newNode->prev = head;
	head = newNode;

	return (head);
}

//gets the first node in linked list
struct List *GetFirstNode(struct List *head)
{

	struct List *current = head;
	while (current && current->prev)
	{
		current = current->prev;
	}
	return (current);
}

/* function to print the list
 * input: Pointer to list
 * output: void
*/
void PrintList(struct List *list)
{
	int count = 0;
	printf("This is a linked list of the integers:\n");
	while (list != NULL)
	{
		printf("%d", list->value);
		list = list->next;
		if (list != NULL)
		{
			printf("<==>");
		}
	}
	printf("\n");
}
