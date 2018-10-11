#ifndef _NODE_H
#define _NODE_H

struct List {
	const char  *text; // 1bytes
	struct List *next; // 4bytes
	struct List *prev; // 4bytes
};

struct List *Insert(struct List* head, char text[BUFSIZ]);
struct List *GetNewLinkedNode(char text[BUFSIZ]);
struct List *GetFirstNode(struct List *head);
void PrintList(struct List *list);
struct List *quicksort(struct List *list );
#endif
