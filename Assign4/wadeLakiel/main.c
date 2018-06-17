#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* 
* Name: Lakiel Wade
* CSU ID: 2601283
* CIS 340: Assignment #4
* Description: main class handles looping and communicate with Node.c
*/

struct List *head;
struct List *tail;
struct List *sorted;


int main(int argc, char **argv)
{
    FILE *fp;
    char data[BUFSIZ];
    head = NULL;
    tail = NULL;
    sorted = NULL;

    //opens the file to be read and inserted into linked list 
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("READ ERROR!!");
        exit(1);
    }
    while (fgets(data, BUFSIZ, fp) != NULL)
    {
        head = Insert(head, data);
    }

    tail = GetFirstNode(head);
    PrintList(tail);
    sorted = quicksort(tail);
    PrintList(sorted);
}