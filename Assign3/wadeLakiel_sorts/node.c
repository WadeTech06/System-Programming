/* 
* Name: Lakiel Wade
* CSU ID: 2601283
* CIS 340: Assignment #3
* Description: class for Linked List. Insert, Sort and, Print Lists
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//Create a new linked node and returns its pointer
struct List *GetNewLinkedNode(int value) {
	//allocate memory 12 bytes
	struct List* newNode = (struct List*)malloc(sizeof(struct List));

	//sets value for new node and set next and prev address to null
	*(int *)&newNode->value = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return (newNode);
}

//Insert a value at head of linked list
struct List *Insert(struct List* head, int value) {

	//Create new Node
	struct List *newNode = GetNewLinkedNode(value);
		
	if(head == NULL) {
		//sets the intial headNode
		head = newNode;
		return(head);
	}
	// sets the next address of head to newNode	
	head->next = newNode;
	//sets the prev address of newNode to head
	newNode->prev = head;
	head = newNode;
	
	return(head);
}

//gets the first node in linked list
struct List *GetFirstNode(struct List *head){

	struct List* current = head;
	while(current && current->prev)	{
		current = current->prev;
	}
	return(current);
}

/* swap two nodes pointed by p and q
 * the nodes are part of a linked list 
 * input: p, a pointer to a node
 *        q, a pointer to a node
 * output: none
*/
void swap(struct List *p, struct List *q)
{
	struct List *tempprev;
	struct List *tempnext;
	if (p==NULL || q==NULL || p == q)
	{
		return;
	}
	tempprev = p->prev;
	tempnext = p->next;
	if (p->next == q)
	{ /*p and q are neighbors */
		if (p->prev != NULL)
		{
			(p->prev)->next = q;
		}
		if (q->next != NULL)
		{
			(q->next)->prev = p;
		}	
		p->prev = q;
		p->next = q->next;
		q->prev = tempprev;
		q->next = p;	
	}
	else if (q->next == p)
	 { /*p and q are neighbors */
		if (p->next != NULL)
		{
			(p->next)->prev = q;
		}
		if (q->prev != NULL)
		{
			(q->prev)->next = p;
		}
		p->prev = q->prev;
		p->next = q;
		q->prev = p;
		q->next = tempnext;	
	}
	else 
	{
		if (p->prev != NULL)
		{
			(p->prev)->next = q;
		}
		if (p->next != NULL)
		{
			(p->next)->prev = q;
		}
		if (q->prev != NULL)
		{
			(q->prev)->next = p;
		}
		if (q->next != NULL)
		{
			(q->next)->prev = p;
		}
		p->prev = q->prev;
		p->next = q->next;
		q->prev = tempprev;
		q->next = tempnext;
	}
}

/* partition the linked list
 * input: first, a pointer to the first node in the list
 *        last, a pointer to the last node in the list
 * output: pivot, a pointer to the pivot node
*/
struct List *partition(struct List *first, struct List *last)
{
	struct List *pivot;
	int pivotval;
	if (first == last)
	{
		return(first);
	}
	pivot = last;
	pivotval = pivot->value;
	(last->prev)->next = NULL;
	last = first;
	while (last!= NULL) 
	{
		if (last->value <= pivotval) 
		{
			swap(first, last);
			first = last->next;
		}
		last = last->next;
	}
	if (first == NULL)
	{ /* pivot happens to be the largest */
		pivot->prev->next = pivot;
	}
	else 
	{ /*insert pivot before first */
		pivot->prev = first->prev;
		pivot->next = first;
		if (first->prev != NULL)
			first->prev->next = pivot;
		first->prev = pivot;
	}
	return(pivot);
}

/* the main function of quicksort
 * input: list, a pointer to the first node in the list
 * output: a pointer to sorted list
*/
struct List *quicksort(struct List *list)
{
		struct List *first, *last, *pivot;
		char sorted = 1;
		if (list == NULL)
		{
			return(list);
		}
		if (list->next == NULL)
		{	
			return(list);
		}
		last = list;
		while (last->next != NULL)
		{
			if (last->value > (last->next)->value)
			{
				sorted = 0;
			}
				last = last->next;
		}
		if (sorted) 
		{
			return(list);
		}

		pivot = partition(list, last);
		list = pivot;

		while (list->prev != NULL) 
		{
			list = list->prev;
		}
		if (pivot->prev != NULL) 
		{
			(pivot->prev)->next = NULL;
		  	first = quicksort(list);
			list = first;
			while (first->next != NULL)
			{
				first = first->next;
			}
			first->next = pivot;
			pivot->prev = first;
		}
		else
		{ /* pivot is the smallest */
			list = pivot;
		}
		if (pivot->next != NULL) 
		{
			pivot->next->prev = NULL;
			last = quicksort(pivot->next);
			pivot->next = last;
			last->prev = pivot;
		}
		return(list);
}

/* function to print the list
 * input: Pointer to list
 * output: void
*/
void PrintList(struct List *list)
{
	int count = 0;
	while(list != NULL) {
		printf("%d",list->value);
		list = list->next;
		if(list!=NULL)
		{
			printf("<==>");
		}
	}
	printf("\n");
}









