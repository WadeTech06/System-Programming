/* 
* Name: Lakiel Wade
* CSU ID: 2601283
* CIS 340: Assignment #4
* Description: class for Linked List. Insert, Sort and, Print Lists
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

//Create a new linked node and returns its pointer
struct List *GetNewLinkedNode(char text[BUFSIZ])
{
    //allocate memory 12 bytes
    struct List *newNode = (struct List *)malloc(sizeof(struct List));

    if (newNode != NULL)
    {
        //sets text for new node and set next and prev address to null
        newNode->text = (char *)malloc(strlen(text) + 1);
        strcpy((char *)newNode->text, text);
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }
    return NULL;
}

//Insert a text at head of linked list
struct List *Insert(struct List *head, char text[BUFSIZ])
{
    //Create new Node
    struct List *newNode = GetNewLinkedNode(text);

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

    return head;
}

//gets the first node in linked list
struct List *GetFirstNode(struct List *head)
{
    while (head && head->prev)
    {
        head = head->prev;
    }
    return (head);
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
    if (p == NULL || q == NULL || p == q)
        return;
    tempprev = p->prev;
    tempnext = p->next;
    if (p->next == q)
    { /*p and q are neighbors */
        if (p->prev != NULL)
            (p->prev)->next = q;
        if (q->next != NULL)
            (q->next)->prev = p;
        p->prev = q;
        p->next = q->next;
        q->prev = tempprev;
        q->next = p;
    }
    else if (q->next == p)
    { /*p and q are neighbors */
        if (p->next != NULL)
            (p->next)->prev = q;
        if (q->prev != NULL)
            (q->prev)->next = p;
        p->prev = q->prev;
        p->next = q;
        q->prev = p;
        q->next = tempnext;
    }
    else
    {
        if (p->prev != NULL)
            (p->prev)->next = q;
        if (p->next != NULL)
            (p->next)->prev = q;
        if (q->prev != NULL)
            (q->prev)->next = p;
        if (q->next != NULL)
            (q->next)->prev = p;
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
    char *pivotval;
    if (first == last)
        return (first);
    pivot = last;
    pivotval = strdup(pivot->text);
    (last->prev)->next = NULL;
    last = first;
    while (last != NULL)
    {
        if ((strcmp(last->text, pivotval)) <= 0)
        {
            swap(first, last);
            first = last->next;
        }
        last = last->next;
    }
    if (first == NULL) /* pivot happens to be the largest */
        pivot->prev->next = pivot;
    else
    { /*insert pivot before first */
        pivot->prev = first->prev;
        pivot->next = first;
        if (first->prev != NULL)
            first->prev->next = pivot;
        first->prev = pivot;
    }
    return (pivot);
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
        return (list);
    if (list->next == NULL)
        return (list);
    last = list;
    while (last->next != NULL)
    {
        if (strcmp(last->text, (last->next)->text) >= 0)
            sorted = 0;
        last = last->next;
    }
    if (sorted)
        return (list);

    pivot = partition(list, last);
    list = pivot;

    while (list->prev != NULL)
        list = list->prev;

    if (pivot->prev != NULL)
    {
        (pivot->prev)->next = NULL;
        first = quicksort(list);
        list = first;
        while (first->next != NULL)
            first = first->next;
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
    return (list);
}

/* Printlist function
* input: list, a pointer to the first node in the list
* output: prints to screen text in list
*/
void PrintList(struct List *list)
{
    if (list == NULL)
        printf("The List is empty.\n");
    while (list != NULL)
    {
        printf("%s", list->text);
        list = list->next;
    }
    printf("\n\n");
}