#ifndef _NODE_H
#define _NODE_H
struct List
{
	int const value;   // 4bytes
	struct List *next; // 4bytes
	struct List *prev; // 4bytes
};

struct List *insertnode(struct List *head, int value);
struct List *GetFirstNode(struct List *head);
void PrintList(struct List *list);
#endif
