#ifndef _LINK_H_
#define _LINK_H_

typedef struct _node{
	int data;
	struct _node* next;
}node;

typedef struct {
	node* head;
	node* tail;
}Linked_List;

void InsertNode(int data, Linked_List* L);
void DeleteNode(int data,Linked_List* L);
void ShowAllNode(Linked_List L);
int FindNode(int data,Linked_List* L);

#endif
